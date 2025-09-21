#include <stdio.h>
#include <stdlib.h>

// =============================================================================
// QUESTION 1: Cycle Detection and Sum Difference in Linked List
// =============================================================================

struct ListNode {
    int val;
    struct ListNode *next;
};

// Floyd's Cycle Detection Algorithm
struct ListNode* detectCycle(struct ListNode* head) {
    if (!head || !head->next) return NULL;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    // Phase 1: Detect if cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    if (!fast || !fast->next) return NULL; // No cycle
    
    // Phase 2: Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow; // Start of cycle
}

int cycleSumDifference(struct ListNode* head) {
    if (!head) return -1;
    
    struct ListNode* cycleStart = detectCycle(head);
    if (!cycleStart) return -1; // No cycle
    
    int beforeSum = 0;
    int cycleSum = 0;
    
    // Calculate sum before cycle
    struct ListNode* curr = head;
    while (curr != cycleStart) {
        beforeSum += curr->val;
        curr = curr->next;
    }
    
    // Calculate sum of cycle nodes
    do {
        cycleSum += curr->val;
        curr = curr->next;
    } while (curr != cycleStart);
    
    return beforeSum - cycleSum;
}

// Helper function to create linked list with cycle
struct ListNode* createListWithCycle(int* values, int n, int pos) {
    if (n == 0) return NULL;
    
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = values[0];
    head->next = NULL;
    
    struct ListNode* curr = head;
    struct ListNode* cycleNode = (pos == 0) ? head : NULL;
    
    for (int i = 1; i < n; i++) {
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = values[i];
        curr->next->next = NULL;
        curr = curr->next;
        
        if (i == pos) cycleNode = curr;
    }
    
    if (pos != -1) {
        curr->next = cycleNode; // Create cycle
    }
    
    return head;
}

// =============================================================================
// QUESTION 2: Separate Odds/Evens and Alternate
// =============================================================================

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

struct Node* separateAndAlternate(struct Node* head) {
    if (!head) return NULL;
    
    struct Node* oddHead = NULL;
    struct Node* oddTail = NULL;
    struct Node* evenHead = NULL;
    struct Node* evenTail = NULL;
    
    // Separate odd and even nodes
    struct Node* curr = head;
    while (curr) {
        if (curr->data % 2 == 1) { // Odd
            if (!oddHead) {
                oddHead = oddTail = createNode(curr->data);
            } else {
                oddTail->next = createNode(curr->data);
                oddTail = oddTail->next;
            }
        } else { // Even
            if (!evenHead) {
                evenHead = evenTail = createNode(curr->data);
            } else {
                evenTail->next = createNode(curr->data);
                evenTail = evenTail->next;
            }
        }
        curr = curr->next;
    }
    
    // Reverse even list
    evenHead = reverseList(evenHead);
    
    // Alternate odd and even
    struct Node* result = NULL;
    struct Node* resultTail = NULL;
    struct Node* oddPtr = oddHead;
    struct Node* evenPtr = evenHead;
    
    while (oddPtr || evenPtr) {
        // Add odd node if available
        if (oddPtr) {
            if (!result) {
                result = resultTail = createNode(oddPtr->data);
            } else {
                resultTail->next = createNode(oddPtr->data);
                resultTail = resultTail->next;
            }
            oddPtr = oddPtr->next;
        }
        
        // Add even node if available
        if (evenPtr) {
            if (!result) {
                result = resultTail = createNode(evenPtr->data);
            } else {
                resultTail->next = createNode(evenPtr->data);
                resultTail = resultTail->next;
            }
            evenPtr = evenPtr->next;
        }
    }
    
    return result;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// =============================================================================
// QUESTION 3: Count Islands in 2D Grid
// =============================================================================

void dfs(char** grid, int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
        return;
    }
    
    grid[i][j] = '0'; // Mark as visited
    
    // Explore all 4 directions
    dfs(grid, i-1, j, rows, cols); // Up
    dfs(grid, i+1, j, rows, cols); // Down
    dfs(grid, i, j-1, rows, cols); // Left
    dfs(grid, i, j+1, rows, cols); // Right
}

int numIslands(char** grid, int rows, int cols) {
    if (!grid || rows == 0 || cols == 0) return 0;
    
    int count = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, rows, cols);
            }
        }
    }
    
    return count;
}

// =============================================================================
// QUESTION 4: Rotate Doubly Linked List by K nodes to the Right
// =============================================================================

struct DLLNode {
    int data;
    struct DLLNode* next;
    struct DLLNode* prev;
};

struct DLLNode* createDLLNode(int data) {
    struct DLLNode* node = malloc(sizeof(struct DLLNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct DLLNode* rotateRight(struct DLLNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    
    // Find length and tail
    int length = 1;
    struct DLLNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    
    k = k % length; // Handle k > length
    if (k == 0) return head;
    
    // Find the new tail (length - k - 1 from start)
    struct DLLNode* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }
    
    struct DLLNode* newHead = newTail->next;
    
    // Break the connection
    newTail->next = NULL;
    newHead->prev = NULL;
    
    // Connect old tail to old head
    tail->next = head;
    head->prev = tail;
    
    return newHead;
}

void printDLL(struct DLLNode* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// =============================================================================
// QUESTION 5: Interval Intersection
// =============================================================================

struct Interval {
    int start;
    int end;
};

struct Interval* intervalIntersection(struct Interval* firstArray, int firstSize,
                                     struct Interval* secondArray, int secondSize,
                                     int* returnSize) {
    *returnSize = 0;
    if (firstSize == 0 || secondSize == 0) return NULL;
    
    struct Interval* result = malloc(sizeof(struct Interval) * (firstSize + secondSize));
    int i = 0, j = 0;
    
    while (i < firstSize && j < secondSize) {
        int start = (firstArray[i].start > secondArray[j].start) ? 
                    firstArray[i].start : secondArray[j].start;
        int end = (firstArray[i].end < secondArray[j].end) ? 
                  firstArray[i].end : secondArray[j].end;
        
        if (start <= end) {
            result[*returnSize].start = start;
            result[*returnSize].end = end;
            (*returnSize)++;
        }
        
        if (firstArray[i].end < secondArray[j].end) {
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}

// =============================================================================
// TEST FUNCTIONS AND MAIN
// =============================================================================

void testQuestion1() {
    printf("=== QUESTION 1 TEST ===\n");
    
    // Test case 1: [3,2,0,-4], pos = 1
    int values1[] = {3, 2, 0, -4};
    struct ListNode* head1 = createListWithCycle(values1, 4, 1);
    printf("Test 1 Result: %d (Expected: 5)\n", cycleSumDifference(head1));
    
    // Test case 2: [1,2], pos = 0  
    int values2[] = {1, 2};
    struct ListNode* head2 = createListWithCycle(values2, 2, 0);
    printf("Test 2 Result: %d (Expected: -3)\n", cycleSumDifference(head2));
    
    // Test case 3: [1], pos = -1
    int values3[] = {1};
    struct ListNode* head3 = createListWithCycle(values3, 1, -1);
    printf("Test 3 Result: %d (Expected: -1)\n", cycleSumDifference(head3));
    
    printf("\n");
}

void testQuestion2() {
    printf("=== QUESTION 2 TEST ===\n");
    
    // Create test list: 1 4 3 2 5 6
    struct Node* head = createNode(1);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    
    printf("Original: ");
    printList(head);
    
    struct Node* result = separateAndAlternate(head);
    printf("Result: ");
    printList(result);
    printf("Expected: 1 6 3 2 5 4\n\n");
}

void testQuestion3() {
    printf("=== QUESTION 3 TEST ===\n");
    
    // Test case 1
    char* grid1[4];
    char row1[] = "11110";
    char row2[] = "11010";
    char row3[] = "11000";
    char row4[] = "00000";
    grid1[0] = row1; grid1[1] = row2; grid1[2] = row3; grid1[3] = row4;
    
    printf("Test 1 Islands: %d (Expected: 1)\n", numIslands(grid1, 4, 5));
    
    printf("\n");
}

void testQuestion4() {
    printf("=== QUESTION 4 TEST ===\n");
    
    // Create DLL: 111 204 319 87 66 18
    struct DLLNode* head = createDLLNode(111);
    head->next = createDLLNode(204);
    head->next->prev = head;
    head->next->next = createDLLNode(319);
    head->next->next->prev = head->next;
    head->next->next->next = createDLLNode(87);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createDLLNode(66);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = createDLLNode(18);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    
    printf("Original: ");
    printDLL(head);
    
    head = rotateRight(head, 2);
    printf("Rotated by 2: ");
    printDLL(head);
    printf("Expected: 66 18 111 204 319 87\n\n");
}

void testQuestion5() {
    printf("=== QUESTION 5 TEST ===\n");
    
    struct Interval first[] = {{0,2}, {5,10}, {13,23}, {24,25}};
    struct Interval second[] = {{1,5}, {8,12}, {15,24}, {25,26}};
    
    int resultSize;
    struct Interval* result = intervalIntersection(first, 4, second, 4, &resultSize);
    
    printf("Intersections:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("[%d,%d]\n", result[i].start, result[i].end);
    }
    printf("Expected: [1,2] [5,5] [8,10] [15,23] [24,24] [25,25]\n");
    
    free(result);
    printf("\n");
}

int main() {
    testQuestion1();
    testQuestion2();
    testQuestion3();
    testQuestion4();
    testQuestion5();
    
    return 0;
}
