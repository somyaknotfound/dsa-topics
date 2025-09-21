#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// =============================================================================
// QUESTION 1: Warehouse Robotics Task Scheduling
// =============================================================================

// Stack for operators
struct OpStack {
    char* items;
    int top;
    int capacity;
};

struct OpStack* createOpStack(int capacity) {
    struct OpStack* stack = malloc(sizeof(struct OpStack));
    stack->items = malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void pushOp(struct OpStack* stack, char op) {
    stack->items[++stack->top] = op;
}

char popOp(struct OpStack* stack) {
    return stack->items[stack->top--];
}

char peekOp(struct OpStack* stack) {
    if (stack->top == -1) return '\0';
    return stack->items[stack->top];
}

int isEmpty(struct OpStack* stack) {
    return stack->top == -1;
}

// Get operator precedence
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

// Check if character is operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Convert infix to postfix
char* infixToPostfix(char* infix) {
    int len = strlen(infix);
    char* postfix = malloc((len + 1) * sizeof(char));
    struct OpStack* stack = createOpStack(len);
    int j = 0;
    
    for (int i = 0; i < len; i++) {
        char c = infix[i];
        
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            pushOp(stack, c);
        }
        else if (c == ')') {
            while (!isEmpty(stack) && peekOp(stack) != '(') {
                postfix[j++] = popOp(stack);
            }
            if (!isEmpty(stack)) popOp(stack); // Remove '('
        }
        else if (isOperator(c)) {
            while (!isEmpty(stack) && peekOp(stack) != '(' && 
                   getPrecedence(peekOp(stack)) >= getPrecedence(c)) {
                postfix[j++] = popOp(stack);
            }
            pushOp(stack, c);
        }
    }
    
    while (!isEmpty(stack)) {
        postfix[j++] = popOp(stack);
    }
    
    postfix[j] = '\0';
    free(stack->items);
    free(stack);
    return postfix;
}

// Convert infix to prefix
char* infixToPrefix(char* infix) {
    int len = strlen(infix);
    
    // Reverse the infix expression
    char* reversed = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        if (infix[len - 1 - i] == '(') {
            reversed[i] = ')';
        } else if (infix[len - 1 - i] == ')') {
            reversed[i] = '(';
        } else {
            reversed[i] = infix[len - 1 - i];
        }
    }
    reversed[len] = '\0';
    
    // Get postfix of reversed expression
    char* postfix = infixToPostfix(reversed);
    
    // Reverse the postfix to get prefix
    int postLen = strlen(postfix);
    char* prefix = malloc((postLen + 1) * sizeof(char));
    for (int i = 0; i < postLen; i++) {
        prefix[i] = postfix[postLen - 1 - i];
    }
    prefix[postLen] = '\0';
    
    free(reversed);
    free(postfix);
    return prefix;
}

// Get task time for operand
int getTaskTime(char operand) {
    switch (operand) {
        case 'A': return 2; // Pick item from Shelf 1
        case 'B': return 1; // Place item on Packing Table
        case 'C': return 3; // Scan Barcode
        case 'D': return 2; // Move to Shipping Area
        default: return 0;
    }
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    int len = strlen(postfix);
    int* stack = malloc(len * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            stack[++top] = getTaskTime(c);
        }
        else if (isOperator(c)) {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int result;
            
            switch (c) {
                case '+': result = operand1 + operand2; break; // Sequential
                case '-': result = operand1; break; // Skip second task
                case '*': result = (operand1 > operand2) ? operand1 : operand2; break; // Parallel
                case '/': result = operand1; break; // Prioritize first
                default: result = 0; break;
            }
            
            stack[++top] = result;
        }
    }
    
    int finalResult = stack[top];
    free(stack);
    return finalResult;
}

void solveQuestion1() {
    printf("=== QUESTION 1: Warehouse Robotics Task Scheduling ===\n");
    
    char infix[] = "(A+B)*(C+D)";
    printf("Input: %s\n", infix);
    
    char* postfix = infixToPostfix(infix);
    char* prefix = infixToPrefix(infix);
    int totalTime = evaluatePostfix(postfix);
    
    printf("Postfix Expression: %s\n", postfix);
    printf("Prefix Expression: %s\n", prefix);
    printf("Total Execution Time: %d\n\n", totalTime);
    
    free(postfix);
    free(prefix);
}

// =============================================================================
// QUESTION 2: Robot Gate Challenge
// =============================================================================

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    
    int maxLen = 0;
    
    // Check all possible substrings
    for (int i = 0; i < len; i++) {
        int balance = 0;
        int currentLen = 0;
        
        for (int j = i; j < len; j++) {
            if (s[j] == '(') {
                balance++;
            } else {
                balance--;
            }
            
            currentLen++;
            
            // If balance becomes negative, invalid sequence
            if (balance < 0) {
                break;
            }
            
            // If balance is 0, we have a valid sequence
            if (balance == 0) {
                maxLen = (currentLen > maxLen) ? currentLen : maxLen;
            }
        }
    }
    
    return maxLen;
}

void solveQuestion2() {
    printf("=== QUESTION 2: Robot Gate Challenge ===\n");
    
    char* testCases[] = {"(()", ")()())(())", "((()))", ""};
    int expected[] = {2, 4, 6, 0};
    int numTests = 4;
    
    for (int i = 0; i < numTests; i++) {
        int result = longestValidParentheses(testCases[i]);
        printf("Input: \"%s\" -> Output: %d (Expected: %d)\n", 
               testCases[i], result, expected[i]);
    }
    printf("\n");
}

// =============================================================================
// QUESTION 3: Forest Fire Containment
// =============================================================================

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue for BFS
struct Queue {
    struct TreeNode** items;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->items = malloc(capacity * sizeof(struct TreeNode*));
    queue->front = queue->rear = queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(struct Queue* queue, struct TreeNode* node) {
    queue->items[queue->rear] = node;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

struct TreeNode* dequeue(struct Queue* queue) {
    struct TreeNode* node = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return node;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Build parent map and find start node
struct TreeNode* buildParentMap(struct TreeNode* root, int start, struct TreeNode** parents, int* mapSize) {
    if (!root) return NULL;
    
    struct Queue* queue = createQueue(100000);
    enqueue(queue, root);
    struct TreeNode* startNode = NULL;
    
    while (!isQueueEmpty(queue)) {
        struct TreeNode* node = dequeue(queue);
        
        if (node->val == start) {
            startNode = node;
        }
        
        if (node->left) {
            parents[(*mapSize)++] = node->left;
            parents[(*mapSize)++] = node;
            enqueue(queue, node->left);
        }
        
        if (node->right) {
            parents[(*mapSize)++] = node->right;
            parents[(*mapSize)++] = node;
            enqueue(queue, node->right);
        }
    }
    
    free(queue->items);
    free(queue);
    return startNode;
}

struct TreeNode* getParent(struct TreeNode* child, struct TreeNode** parents, int mapSize) {
    for (int i = 0; i < mapSize; i += 2) {
        if (parents[i] == child) {
            return parents[i + 1];
        }
    }
    return NULL;
}

int amountOfTime(struct TreeNode* root, int start) {
    if (!root) return 0;
    
    // Build parent mapping
    struct TreeNode** parents = malloc(200000 * sizeof(struct TreeNode*));
    int mapSize = 0;
    struct TreeNode* startNode = buildParentMap(root, start, parents, &mapSize);
    
    // BFS from start node
    struct Queue* queue = createQueue(100000);
    struct TreeNode** visited = malloc(100000 * sizeof(struct TreeNode*));
    int visitedSize = 0;
    
    enqueue(queue, startNode);
    visited[visitedSize++] = startNode;
    
    int time = 0;
    
    while (!isQueueEmpty(queue)) {
        int levelSize = queue->size;
        int burned = 0;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(queue);
            
            // Check neighbors: parent, left child, right child
            struct TreeNode* neighbors[] = {
                getParent(node, parents, mapSize),
                node->left,
                node->right
            };
            
            for (int j = 0; j < 3; j++) {
                struct TreeNode* neighbor = neighbors[j];
                if (neighbor) {
                    // Check if already visited
                    int alreadyVisited = 0;
                    for (int k = 0; k < visitedSize; k++) {
                        if (visited[k] == neighbor) {
                            alreadyVisited = 1;
                            break;
                        }
                    }
                    
                    if (!alreadyVisited) {
                        visited[visitedSize++] = neighbor;
                        enqueue(queue, neighbor);
                        burned = 1;
                    }
                }
            }
        }
        
        if (burned) time++;
    }
    
    free(parents);
    free(visited);
    free(queue->items);
    free(queue);
    
    return time;
}

void solveQuestion3() {
    printf("=== QUESTION 3: Forest Fire Containment ===\n");
    
    // Test Case 1: Tree with fire starting at leaf
    struct TreeNode* root1 = createTreeNode(1);
    root1->left = createTreeNode(5);
    root1->right = createTreeNode(3);
    root1->right->left = createTreeNode(10);
    root1->right->right = createTreeNode(6);
    
    int result1 = amountOfTime(root1, 10);
    printf("Test Case 1 - Fire at leaf (node 10): %d minutes (Expected: 3)\n", result1);
    
    // Test Case 2: Single node
    struct TreeNode* root2 = createTreeNode(42);
    int result2 = amountOfTime(root2, 42);
    printf("Test Case 2 - Single node: %d minutes (Expected: 0)\n", result2);
    
    printf("\n");
}

// =============================================================================
// QUESTION 4: CPU Scheduling FCFS
// =============================================================================

struct Process {
    int pid;
    int at;  // arrival time
    int bt;  // burst time
    int st;  // start time
    int ct;  // completion time
    int wt;  // waiting time
    int tt;  // turnaround time
};

void scheduleFCFS(struct Process* processes, int n) {
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        // Start time is max of current time and arrival time
        processes[i].st = (currentTime > processes[i].at) ? currentTime : processes[i].at;
        
        // Completion time = start time + burst time
        processes[i].ct = processes[i].st + processes[i].bt;
        
        // Waiting time = start time - arrival time
        processes[i].wt = processes[i].st - processes[i].at;
        
        // Turnaround time = completion time - arrival time
        processes[i].tt = processes[i].ct - processes[i].at;
        
        // Update current time
        currentTime = processes[i].ct;
    }
}

void solveQuestion4() {
    printf("=== QUESTION 4: CPU Scheduling FCFS ===\n");
    
    int n = 3;
    struct Process processes[] = {
        {1, 0, 4, 0, 0, 0, 0},  // pid, at, bt, st, ct, wt, tt
        {2, 1, 3, 0, 0, 0, 0},
        {3, 2, 1, 0, 0, 0, 0}
    };
    
    scheduleFCFS(processes, n);
    
    printf("PID\tAT\tBT\tST\tCT\tWT\tTT\n");
    
    double totalWT = 0, totalTT = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i].pid, processes[i].at, processes[i].bt,
               processes[i].st, processes[i].ct, processes[i].wt, processes[i].tt);
        totalWT += processes[i].wt;
        totalTT += processes[i].tt;
    }
    
    printf("Average WT: %.2f\n", totalWT / n);
    printf("Average TT: %.2f\n\n", totalTT / n);
}

// =============================================================================
// QUESTION 5: Shortest Subarray with Sum >= k
// =============================================================================

struct Deque {
    int* items;
    int front, rear, size, capacity;
};

struct Deque* createDeque(int capacity) {
    struct Deque* deque = malloc(sizeof(struct Deque));
    deque->items = malloc(capacity * sizeof(int));
    deque->front = deque->rear = deque->size = 0;
    deque->capacity = capacity;
    return deque;
}

void pushBack(struct Deque* deque, int val) {
    deque->items[deque->rear] = val;
    deque->rear = (deque->rear + 1) % deque->capacity;
    deque->size++;
}

void pushFront(struct Deque* deque, int val) {
    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    deque->items[deque->front] = val;
    deque->size++;
}

int popFront(struct Deque* deque) {
    int val = deque->items[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return val;
}

int popBack(struct Deque* deque) {
    deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    int val = deque->items[deque->rear];
    deque->size--;
    return val;
}

int front(struct Deque* deque) {
    return deque->items[deque->front];
}

int back(struct Deque* deque) {
    return deque->items[(deque->rear - 1 + deque->capacity) % deque->capacity];
}

int isDequeEmpty(struct Deque* deque) {
    return deque->size == 0;
}

int shortestSubarray(int* nums, int numsSize, int k) {
    long long* prefixSum = malloc((numsSize + 1) * sizeof(long long));
    prefixSum[0] = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    struct Deque* deque = createDeque(numsSize + 1);
    int minLen = INT_MAX;
    
    for (int i = 0; i <= numsSize; i++) {
        // Remove indices from front where sum condition is satisfied
        while (!isDequeEmpty(deque) && prefixSum[i] - prefixSum[front(deque)] >= k) {
            int len = i - popFront(deque);
            minLen = (len < minLen) ? len : minLen;
        }
        
        // Maintain deque in increasing order of prefix sums
        while (!isDequeEmpty(deque) && prefixSum[back(deque)] >= prefixSum[i]) {
            popBack(deque);
        }
        
        pushBack(deque, i);
    }
    
    free(prefixSum);
    free(deque->items);
    free(deque);
    
    return minLen == INT_MAX ? -1 : minLen;
}

void solveQuestion5() {
    printf("=== QUESTION 5: Shortest Subarray with Sum >= k ===\n");
    
    // Test cases
    int nums1[] = {2, -1, 2};
    int result1 = shortestSubarray(nums1, 3, 3);
    printf("Test 1: [2, -1, 2], k=3 -> Result: %d (Expected: 3)\n", result1);
    
    int nums2[] = {1, 2};
    int result2 = shortestSubarray(nums2, 2, 4);
    printf("Test 2: [1, 2], k=4 -> Result: %d (Expected: -1)\n", result2);
    
    int nums3[] = {84, -37, 32, 40, 95};
    int result3 = shortestSubarray(nums3, 5, 167);
    printf("Test 3: [84, -37, 32, 40, 95], k=167 -> Result: %d (Expected: 3)\n", result3);
    
    printf("\n");
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================

int main() {
    printf("CS 203 Assignment 3 Solutions\n");
    printf("==============================\n\n");
    
    solveQuestion1();
    solveQuestion2();
    solveQuestion3();
    solveQuestion4();
    solveQuestion5();
    
    return 0;
}
