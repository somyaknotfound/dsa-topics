#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* front;
    Node* back;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = NULL;
    dq->back = NULL;
    dq->size = 0;
    return dq;
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

void push_back(Deque* dq, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = dq->back;
    
    if (isEmpty(dq)) {
        dq->front = dq->back = newNode;
    } else {
        dq->back->next = newNode;
        dq->back = newNode;
    }
    dq->size++;
}

void push_front(Deque* dq, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = dq->front;
    newNode->prev = NULL;
    
    if (isEmpty(dq)) {
        dq->front = dq->back = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

int pop_front(Deque* dq) {
    if (isEmpty(dq)) return -1;
    
    Node* temp = dq->front;
    int data = temp->data;
    
    if (dq->size == 1) {
        dq->front = dq->back = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }
    
    free(temp);
    dq->size--;
    return data;
}

int pop_back(Deque* dq) {
    if (isEmpty(dq)) return -1;
    
    Node* temp = dq->back;
    int data = temp->data;
    
    if (dq->size == 1) {
        dq->front = dq->back = NULL;
    } else {
        dq->back = dq->back->prev;
        dq->back->next = NULL;
    }
    
    free(temp);
    dq->size--;
    return data;
}

int front(Deque* dq) {
    if (isEmpty(dq)) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if (isEmpty(dq)) return -1;
    return dq->back->data;
}

int shortestSubarray(int* nums, int numsSize, int k) {
    if (numsSize == 0) return -1;
    
    long long* prefixSum = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefixSum[0] = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    Deque* dq = createDeque();
    int minLen = INT_MAX;
    
    for (int i = 0; i <= numsSize; i++) {
        while (!isEmpty(dq) && prefixSum[i] - prefixSum[front(dq)] >= k) {
            int len = i - pop_front(dq);
            if (len < minLen) {
                minLen = len;
            }
        }
        
        while (!isEmpty(dq) && prefixSum[back(dq)] >= prefixSum[i]) {
            pop_back(dq);
        }
        
        push_back(dq, i);
    }
    
    free(prefixSum);
    
    Node* current = dq->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(dq);
    
    return minLen == INT_MAX ? -1 : minLen;
}

void printDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    
    printf("Deque contents (front to back): ");
    Node* current = dq->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int* nums = (int*)malloc(n * sizeof(int));
    
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Enter k: ");
    scanf("%d", &k);
    
    printf("\nTesting Deque operations:\n");
    Deque* testDq = createDeque();
    
    printf("Pushing elements to back: ");
    for (int i = 0; i < 3 && i < n; i++) {
        push_back(testDq, nums[i]);
        printf("%d ", nums[i]);
    }
    printf("\n");
    printDeque(testDq);
    
    printf("Front element: %d\n", front(testDq));
    printf("Back element: %d\n", back(testDq));
    
    printf("Popping from front: %d\n", pop_front(testDq));
    printDeque(testDq);
    
    Node* current = testDq->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(testDq);
    
    int result = shortestSubarray(nums, n, k);
    
    printf("\nShortest subarray length with sum >= %d: ", k);
    if (result == -1) {
        printf("No such subarray exists\n");
    } else {
        printf("%d\n", result);
    }
    
    free(nums);
    return 0;
}