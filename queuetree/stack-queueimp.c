#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 1000

// ====================== STACK IMPLEMENTATION ======================

typedef struct {
    int items[MAX_SIZE];
    int top;
    int capacity;
} Stack;

// Stack operations
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = MAX_SIZE;
    return stack;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}

void printStack(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// ====================== QUEUE IMPLEMENTATION ======================

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// Queue operations
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = MAX_SIZE;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

bool isQueueFull(Queue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int frontQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->items[queue->front];
}

void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->items[index]);
    }
    printf("\n");
}

// ====================== STACK PROBLEMS ======================

// Problem 1: Check for balanced parentheses
bool isBalancedParentheses(char* expr) {
    Stack* stack = createStack();
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        // Push opening brackets
        if (ch == '(' || ch == '[' || ch == '{') {
            push(stack, ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isStackEmpty(stack)) {
                free(stack);
                return false;
            }
            
            char top = pop(stack);
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                free(stack);
                return false;
            }
        }
    }
    
    bool result = isStackEmpty(stack);
    free(stack);
    return result;
}

// Problem 2: Evaluate postfix expression
int evaluatePostfix(char* expr) {
    Stack* stack = createStack();
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        if (ch == ' ') continue;
        
        // If operand, push to stack
        if (isdigit(ch)) {
            push(stack, ch - '0');
        }
        // If operator, pop two operands and evaluate
        else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;
            
            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: 
                    printf("Invalid operator: %c\n", ch);
                    free(stack);
                    return -1;
            }
            push(stack, result);
        }
    }
    
    int result = pop(stack);
    free(stack);
    return result;
}

// Problem 3: Next Greater Element
void nextGreaterElement(int arr[], int n) {
    Stack* stack = createStack();
    int* result = (int*)malloc(n * sizeof(int));
    
    // Initialize result array with -1
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    
    // Process all array elements
    for (int i = 0; i < n; i++) {
        // Pop elements smaller than current element
        while (!isStackEmpty(stack) && arr[peek(stack)] < arr[i]) {
            int index = pop(stack);
            result[index] = arr[i];
        }
        push(stack, i);  // Push current index
    }
    
    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }
    
    free(result);
    free(stack);
}

// Problem 4: Reverse a string using stack
void reverseString(char* str) {
    Stack* stack = createStack();
    int len = strlen(str);
    
    // Push all characters to stack
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    
    // Pop all characters back to string
    for (int i = 0; i < len; i++) {
        str[i] = pop(stack);
    }
    
    free(stack);
}

// ====================== QUEUE PROBLEMS ======================

// Problem 1: Generate binary numbers from 1 to N
void generateBinaryNumbers(int n) {
    Queue* queue = createQueue();
    enqueue(queue, 1);
    
    printf("Binary representations from 1 to %d:\n", n);
    
    for (int i = 1; i <= n; i++) {
        int num = dequeue(queue);
        
        // Print current binary number
        printf("%d: ", i);
        int temp = num;
        char binary[32];
        int index = 0;
        
        while (temp > 0) {
            binary[index++] = (temp % 10) + '0';
            temp /= 10;
        }
        
        // Print in reverse order
        for (int j = index - 1; j >= 0; j--) {
            printf("%c", binary[j]);
        }
        printf("\n");
        
        // Generate next binary numbers
        enqueue(queue, num * 10);      // Append 0
        enqueue(queue, num * 10 + 1);  // Append 1
    }
    
    free(queue);
}

// Problem 2: First non-repeating character in stream
void firstNonRepeatingChar() {
    Queue* queue = createQueue();
    int charCount[256] = {0};  // ASCII characters
    char stream[] = "aabc";
    
    printf("First non-repeating character in stream:\n");
    
    for (int i = 0; stream[i] != '\0'; i++) {
        char ch = stream[i];
        charCount[ch]++;
        enqueue(queue, ch);
        
        // Remove characters that are no longer non-repeating
        while (!isQueueEmpty(queue) && charCount[frontQueue(queue)] > 1) {
            dequeue(queue);
        }
        
        if (isQueueEmpty(queue)) {
            printf("After '%c': -1\n", ch);
        } else {
            printf("After '%c': %c\n", ch, frontQueue(queue));
        }
    }
    
    free(queue);
}

// Problem 3: Level order traversal simulation
void levelOrderTraversal() {
    Queue* queue = createQueue();
    
    // Simulate a binary tree: 1, 2, 3, 4, 5, 6, 7
    int tree[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    
    enqueue(queue, 0);  // Start with root index
    printf("Level order traversal: ");
    
    while (!isQueueEmpty(queue)) {
        int index = dequeue(queue);
        printf("%d ", tree[index]);
        
        // Add left child
        int leftChild = 2 * index + 1;
        if (leftChild < n) {
            enqueue(queue, leftChild);
        }
        
        // Add right child
        int rightChild = 2 * index + 2;
        if (rightChild < n) {
            enqueue(queue, rightChild);
        }
    }
    printf("\n");
    
    free(queue);
}

// ====================== DEMO AND TESTS ======================

void demonstrateStackOperations() {
    printf("\n=== STACK OPERATIONS DEMO ===\n");
    Stack* stack = createStack();
    
    printf("Pushing elements: 10, 20, 30, 40\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    printStack(stack);
    
    printf("Peek: %d\n", peek(stack));
    printf("Popping: %d\n", pop(stack));
    printf("Popping: %d\n", pop(stack));
    printStack(stack);
    
    free(stack);
}

void demonstrateQueueOperations() {
    printf("\n=== QUEUE OPERATIONS DEMO ===\n");
    Queue* queue = createQueue();
    
    printf("Enqueuing elements: 10, 20, 30, 40\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    printQueue(queue);
    
    printf("Front: %d\n", frontQueue(queue));
    printf("Dequeuing: %d\n", dequeue(queue));
    printf("Dequeuing: %d\n", dequeue(queue));
    printQueue(queue);
    
    free(queue);
}

void testStackProblems() {
    printf("\n=== STACK PROBLEMS ===\n");
    
    // Test balanced parentheses
    printf("1. Balanced Parentheses:\n");
    char* expressions[] = {"((()))", "((())", "{[()]}", "({[}])"};
    for (int i = 0; i < 4; i++) {
        printf("'%s' is %s\n", expressions[i], 
               isBalancedParentheses(expressions[i]) ? "balanced" : "not balanced");
    }
    
    // Test postfix evaluation
    printf("\n2. Postfix Evaluation:\n");
    char postfix[] = "23*54*+";
    printf("'%s' = %d\n", postfix, evaluatePostfix(postfix));
    
    // Test next greater element
    printf("\n3. Next Greater Element:\n");
    int arr[] = {4, 5, 2, 25, 7, 8};
    nextGreaterElement(arr, 6);
    
    // Test string reversal
    printf("\n4. String Reversal:\n");
    char str[] = "hello";
    printf("Original: %s\n", str);
    reverseString(str);
    printf("Reversed: %s\n", str);
}

void testQueueProblems() {
    printf("\n=== QUEUE PROBLEMS ===\n");
    
    // Test binary number generation
    printf("1. Binary Number Generation:\n");
    generateBinaryNumbers(5);
    
    // Test first non-repeating character
    printf("\n2. First Non-Repeating Character:\n");
    firstNonRepeatingChar();
    
    // Test level order traversal
    printf("\n3. Level Order Traversal:\n");
    levelOrderTraversal();
}

int main() {
    demonstrateStackOperations();
    demonstrateQueueOperations();
    testStackProblems();
    testQueueProblems();
    
    printf("\n=== COMPLEXITY ANALYSIS ===\n");
    printf("Stack Operations: Push/Pop/Peek - O(1)\n");
    printf("Queue Operations: Enqueue/Dequeue/Front - O(1)\n");
    printf("Space Complexity: O(n) where n is number of elements\n");
    
    return 0;
}
