#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int get_task_time(char task) {
    switch(task) {
        case 'A': return 2;
        case 'B': return 1;
        case 'C': return 3;
        case 'D': return 2;
        default: return 0;
    }
}

typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

void init_char_stack(CharStack *s) {
    s->top = -1;
}

int is_char_empty(CharStack *s) {
    return s->top == -1;
}

void push_char(CharStack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++s->top] = c;
    }
}

char pop_char(CharStack *s) {
    if (!is_char_empty(s)) {
        return s->data[s->top--];
    }
    return '\0';
}

char peek_char(CharStack *s) {
    if (!is_char_empty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

typedef struct {
    int data[MAX_SIZE];
    int top;
} IntStack;

void init_int_stack(IntStack *s) {
    s->top = -1;
}

int is_int_empty(IntStack *s) {
    return s->top == -1;
}

void push_int(IntStack *s, int val) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++s->top] = val;
    }
}

int pop_int(IntStack *s) {
    if (!is_int_empty(s)) {
        return s->data[s->top--];
    }
    return 0;
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    CharStack stack;
    init_char_stack(&stack);
    
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        
        if (isalpha(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push_char(&stack, c);
        }
        else if (c == ')') {
            while (!is_char_empty(&stack) && peek_char(&stack) != '(') {
                postfix[j++] = pop_char(&stack);
            }
            pop_char(&stack);
        }
        else if (is_operator(c)) {
            while (!is_char_empty(&stack) && peek_char(&stack) != '(' && 
                   precedence(peek_char(&stack)) >= precedence(c)) {
                postfix[j++] = pop_char(&stack);
            }
            push_char(&stack, c);
        }
    }
    
    while (!is_char_empty(&stack)) {
        postfix[j++] = pop_char(&stack);
    }
    postfix[j] = '\0';
}

void infix_to_prefix(char *infix, char *prefix) {
    int len = strlen(infix);
    char reversed[MAX_SIZE];
    strcpy(reversed, infix);
    reverse_string(reversed);
    
    for (int i = 0; i < len; i++) {
        if (reversed[i] == '(') {
            reversed[i] = ')';
        } else if (reversed[i] == ')') {
            reversed[i] = '(';
        }
    }
    
    char temp_postfix[MAX_SIZE];
    infix_to_postfix(reversed, temp_postfix);
    
    strcpy(prefix, temp_postfix);
    reverse_string(prefix);
}

int calculate_execution_time(char *postfix) {
    IntStack stack;
    init_int_stack(&stack);
    
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        
        if (isalpha(c)) {
            push_int(&stack, get_task_time(c));
        }
        else if (is_operator(c)) {
            int time2 = pop_int(&stack);
            int time1 = pop_int(&stack);
            int result;
            
            switch(c) {
                case '+':
                    result = time1 + time2;
                    break;
                case '-':
                    result = time1;
                    break;
                case '*':
                    result = (time1 > time2) ? time1 : time2;
                    break;
                case '/':
                    result = time1;
                    break;
                default:
                    result = 0;
            }
            push_int(&stack, result);
        }
    }
    
    return pop_int(&stack);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    char prefix[MAX_SIZE];
    
    scanf("%s", infix);
    
    infix_to_postfix(infix, postfix);
    infix_to_prefix(infix, prefix);
    
    int total_time = calculate_execution_time(postfix);
    
    printf("%s\n", postfix);
    printf("%s\n", prefix);
    printf("%d\n", total_time);
    
    return 0;
}