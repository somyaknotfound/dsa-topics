#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

// ===================== 1. TRAPPING RAIN WATER (LC #42) =====================
// Two pointer approach - O(n) time, O(1) space

int trap(int* height, int heightSize) {
    if (heightSize <= 2) return 0;
    
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }
    
    return water;
}

// ===================== 2. SLIDING WINDOW MAXIMUM (LC #239) =====================
// Using deque to maintain window maximum - O(n) time

typedef struct {
    int* arr;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(capacity * sizeof(int));
    dq->front = 0;
    dq->rear = -1;
    dq->capacity = capacity;
    return dq;
}

bool isEmpty(Deque* dq) { return dq->rear < dq->front; }
void pushBack(Deque* dq, int val) { dq->arr[++dq->rear] = val; }
int popBack(Deque* dq) { return dq->arr[dq->rear--]; }
int popFront(Deque* dq) { return dq->arr[dq->front++]; }
int front(Deque* dq) { return dq->arr[dq->front]; }
int back(Deque* dq) { return dq->arr[dq->rear]; }

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int* result = (int*)malloc(*returnSize * sizeof(int));
    Deque* dq = createDeque(numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        // Remove indices outside current window
        while (!isEmpty(dq) && front(dq) <= i - k) {
            popFront(dq);
        }
        
        // Remove smaller elements from rear
        while (!isEmpty(dq) && nums[back(dq)] <= nums[i]) {
            popBack(dq);
        }
        
        pushBack(dq, i);
        
        // Add to result if window is complete
        if (i >= k - 1) {
            result[i - k + 1] = nums[front(dq)];
        }
    }
    
    free(dq->arr);
    free(dq);
    return result;
}

// ===================== 3. MERGE K SORTED LISTS (LC #23) =====================
// Divide and conquer approach

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];
    
    while (listsSize > 1) {
        int mergedIndex = 0;
        
        for (int i = 0; i < listsSize; i += 2) {
            struct ListNode* l1 = lists[i];
            struct ListNode* l2 = (i + 1 < listsSize) ? lists[i + 1] : NULL;
            lists[mergedIndex++] = mergeTwoLists(l1, l2);
        }
        
        listsSize = mergedIndex;
    }
    
    return lists[0];
}

// ===================== 4. LARGEST RECTANGLE IN HISTOGRAM (LC #84) =====================
// Using stack to find largest rectangle

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;
    
    for (int i = 0; i <= heightsSize; i++) {
        int currentHeight = (i == heightsSize) ? 0 : heights[i];
        
        while (top >= 0 && heights[stack[top]] > currentHeight) {
            int height = heights[stack[top--]];
            int width = (top >= 0) ? (i - stack[top] - 1) : i;
            int area = height * width;
            maxArea = maxArea > area ? maxArea : area;
        }
        
        stack[++top] = i;
    }
    
    free(stack);
    return maxArea;
}

// ===================== 5. REVERSE NODES IN K-GROUP (LC #25) =====================
// Reverse linked list in groups of k

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;
    
    // Check if we have k nodes
    struct ListNode* temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) return head;
        temp = temp->next;
    }
    
    // Reverse first k nodes
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    for (int i = 0; i < k; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Recursively reverse remaining groups
    head->next = reverseKGroup(curr, k);
    
    return prev;
}

// ===================== 6. MINIMUM WINDOW SUBSTRING (LC #76) =====================
// Sliding window with character frequency

char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    
    if (sLen == 0 || tLen == 0) return "";
    
    // Frequency map for characters in t
    int tFreq[128] = {0};
    for (int i = 0; i < tLen; i++) {
        tFreq[t[i]]++;
    }
    
    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (tFreq[i] > 0) required++;
    }
    
    int left = 0, right = 0;
    int formed = 0;
    int windowCounts[128] = {0};
    
    int minLen = INT_MAX;
    int minLeft = 0;
    
    while (right < sLen) {
        // Add character from right to window
        char c = s[right];
        windowCounts[c]++;
        
        if (tFreq[c] > 0 && windowCounts[c] == tFreq[c]) {
            formed++;
        }
        
        // Try to contract window
        while (left <= right && formed == required) {
            c = s[left];
            
            // Update minimum window
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            // Remove from left
            windowCounts[c]--;
            if (tFreq[c] > 0 && windowCounts[c] < tFreq[c]) {
                formed--;
            }
            
            left++;
        }
        
        right++;
    }
    
    if (minLen == INT_MAX) return "";
    
    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(result, s + minLeft, minLen);
    result[minLen] = '\0';
    
    return result;
}

// ===================== 7. VALID NUMBER (LC #65) =====================
// String parsing for number validation

bool isNumber(char* s) {
    int len = strlen(s);
    if (len == 0) return false;
    
    int i = 0;
    
    // Skip leading whitespace
    while (i < len && s[i] == ' ') i++;
    if (i == len) return false;
    
    // Check for sign
    if (i < len && (s[i] == '+' || s[i] == '-')) i++;
    
    bool hasNum = false;
    bool hasDot = false;
    bool hasExp = false;
    
    while (i < len) {
        char c = s[i];
        
        if (c >= '0' && c <= '9') {
            hasNum = true;
        } else if (c == '.') {
            if (hasDot || hasExp) return false;
            hasDot = true;
        } else if (c == 'e' || c == 'E') {
            if (hasExp || !hasNum) return false;
            hasExp = true;
            hasNum = false; // Reset for exponent part
        } else if (c == '+' || c == '-') {
            if (s[i-1] != 'e' && s[i-1] != 'E') return false;
        } else if (c == ' ') {
            break; // Start of trailing whitespace
        } else {
            return false; // Invalid character
        }
        
        i++;
    }
    
    // Skip trailing whitespace
    while (i < len && s[i] == ' ') i++;
    
    return hasNum && i == len;
}

// ===================== 8. BINARY TREE MAXIMUM PATH SUM (LC #124) =====================
// Tree traversal with path sum calculation

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxPathSumHelper(struct TreeNode* node, int* maxSum) {
    if (!node) return 0;
    
    // Get max path sum from left and right subtrees
    int leftMax = fmax(0, maxPathSumHelper(node->left, maxSum));
    int rightMax = fmax(0, maxPathSumHelper(node->right, maxSum));
    
    // Current path sum including node
    int currentPathSum = node->val + leftMax + rightMax;
    
    // Update global maximum
    *maxSum = fmax(*maxSum, currentPathSum);
    
    // Return max path sum that can be extended to parent
    return node->val + fmax(leftMax, rightMax);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}

// ===================== 9. SERIALIZE AND DESERIALIZE BST (LC #449) =====================
// BST serialization using preorder traversal

void serializeHelper(struct TreeNode* root, char* result, int* index) {
    if (!root) return;
    
    sprintf(result + *index, "%d,", root->val);
    *index = strlen(result);
    
    serializeHelper(root->left, result, index);
    serializeHelper(root->right, result, index);
}

char* serialize(struct TreeNode* root) {
    char* result = (char*)malloc(10000 * sizeof(char));
    result[0] = '\0';
    int index = 0;
    
    serializeHelper(root, result, &index);
    return result;
}

struct TreeNode* deserializeHelper(char* data, int* index, int minVal, int maxVal) {
    if (*index >= strlen(data)) return NULL;
    
    // Parse next number
    int val = 0;
    int sign = 1;
    bool hasNum = false;
    
    if (data[*index] == '-') {
        sign = -1;
        (*index)++;
    }
    
    while (*index < strlen(data) && data[*index] >= '0' && data[*index] <= '9') {
        val = val * 10 + (data[*index] - '0');
        (*index)++;
        hasNum = true;
    }
    
    if (!hasNum) return NULL;
    val *= sign;
    
    // Skip comma
    if (*index < strlen(data) && data[*index] == ',') {
        (*index)++;
    }
    
    // Check BST property
    if (val < minVal || val > maxVal) {
        // Backtrack
        while (*index > 0 && data[*index - 1] != ',') {
            (*index)--;
        }
        return NULL;
    }
    
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = deserializeHelper(data, index, minVal, val);
    node->right = deserializeHelper(data, index, val, maxVal);
    
    return node;
}

struct TreeNode* deserialize(char* data) {
    if (!data || strlen(data) == 0) return NULL;
    int index = 0;
    return deserializeHelper(data, &index, INT_MIN, INT_MAX);
}

// ===================== DEMO FUNCTIONS =====================

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void printList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("]\n");
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void demoTrapWater() {
    printf("=== TRAPPING RAIN WATER ===\n");
    int heights[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = 12;
    
    printf("Heights: ");
    printArray(heights, size);
    printf("Water trapped: %d units\n\n", trap(heights, size));
}

void demoSlidingWindow() {
    printf("=== SLIDING WINDOW MAXIMUM ===\n");
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int size = 8;
    int k = 3;
    int returnSize;
    
    printf("Array: ");
    printArray(nums, size);
    printf("Window size: %d\n", k);
    
    int* result = maxSlidingWindow(nums, size, k, &returnSize);
    printf("Maximum in each window: ");
    printArray(result, returnSize);
    printf("\n");
    
    free(result);
}

void demoMergeKLists() {
    printf("=== MERGE K SORTED LISTS ===\n");
    
    // Create test lists: [1,4,5], [1,3,4], [2,6]
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(5);
    
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    
    struct ListNode* list3 = createNode(2);
    list3->next = createNode(6);
    
    struct ListNode* lists[] = {list1, list2, list3};
    
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    printf("List 3: ");
    printList(list3);
    
    struct ListNode* merged = mergeKLists(lists, 3);
    printf("Merged: ");
    printList(merged);
    printf("\n");
}

void demoLargestRectangle() {
    printf("=== LARGEST RECTANGLE IN HISTOGRAM ===\n");
    int heights[] = {2,1,5,6,2,3};
    int size = 6;
    
    printf("Heights: ");
    printArray(heights, size);
    printf("Largest rectangle area: %d\n\n", largestRectangleArea(heights, size));
}

void demoMinWindow() {
    printf("=== MINIMUM WINDOW SUBSTRING ===\n");
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    
    printf("String s: %s\n", s);
    printf("String t: %s\n", t);
    printf("Minimum window: %s\n\n", minWindow(s, t));
}

int main() {
    printf("FAMOUS LEETCODE HARD PROBLEMS\n");
    printf("=============================\n\n");
    
    demoTrapWater();
    demoSlidingWindow();
    demoMergeKLists();
    demoLargestRectangle();
    demoMinWindow();
    
    return 0;
}

/*
 * PROBLEM CATEGORIES COVERED:
 * ===========================
 * 
 * ARRAYS & TWO POINTERS:
 * - Trapping Rain Water: Two pointer technique
 * - Sliding Window Maximum: Deque for window operations
 * 
 * LINKED LISTS:
 * - Merge K Sorted Lists: Divide and conquer
 * - Reverse Nodes in K-Group: List manipulation
 * 
 * STACKS:
 * - Largest Rectangle in Histogram: Monotonic stack
 * 
 * STRINGS & SLIDING WINDOW:
 * - Minimum Window Substring: Character frequency tracking
 * - Valid Number: String parsing and validation
 * 
 * BINARY TREES & BST:
 * - Binary Tree Maximum Path Sum: Tree traversal
 * - Serialize/Deserialize BST: Tree serialization
 * 
 * KEY TECHNIQUES:
 * - Two pointers for array problems
 * - Deque for sliding window maximum/minimum
 * - Stack for histogram and parentheses problems
 * - Sliding window for substring problems
 * - Tree traversal with global state tracking
 * - BST properties for serialization
 */
