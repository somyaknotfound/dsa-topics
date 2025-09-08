#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Array-based Deque Implementation
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} ArrayDeque;

// Linked List Node for Dynamic Deque
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Linked List-based Deque Implementation
typedef struct {
    Node* front;
    Node* rear;
    int size;
} LinkedDeque;

// ===================== ARRAY-BASED DEQUE =====================

ArrayDeque* createArrayDeque() {
    ArrayDeque* dq = (ArrayDeque*)malloc(sizeof(ArrayDeque));
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

bool isArrayDequeEmpty(ArrayDeque* dq) {
    return dq->size == 0;
}

bool isArrayDequeFull(ArrayDeque* dq) {
    return dq->size == MAX_SIZE;
}

void insertFront(ArrayDeque* dq, int data) {
    if (isArrayDequeFull(dq)) {
        printf("Deque is full! Cannot insert at front.\n");
        return;
    }
    
    if (isArrayDequeEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    
    dq->arr[dq->front] = data;
    dq->size++;
    printf("Inserted %d at front\n", data);
}

void insertRear(ArrayDeque* dq, int data) {
    if (isArrayDequeFull(dq)) {
        printf("Deque is full! Cannot insert at rear.\n");
        return;
    }
    
    if (isArrayDequeEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    
    dq->arr[dq->rear] = data;
    dq->size++;
    printf("Inserted %d at rear\n", data);
}

int deleteFront(ArrayDeque* dq) {
    if (isArrayDequeEmpty(dq)) {
        printf("Deque is empty! Cannot delete from front.\n");
        return -1;
    }
    
    int data = dq->arr[dq->front];
    
    if (dq->size == 1) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    
    dq->size--;
    printf("Deleted %d from front\n", data);
    return data;
}

int deleteRear(ArrayDeque* dq) {
    if (isArrayDequeEmpty(dq)) {
        printf("Deque is empty! Cannot delete from rear.\n");
        return -1;
    }
    
    int data = dq->arr[dq->rear];
    
    if (dq->size == 1) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    
    dq->size--;
    printf("Deleted %d from rear\n", data);
    return data;
}

int getFront(ArrayDeque* dq) {
    if (isArrayDequeEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int getRear(ArrayDeque* dq) {
    if (isArrayDequeEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

void displayArrayDeque(ArrayDeque* dq) {
    if (isArrayDequeEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    
    printf("Deque (front to rear): ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// ===================== LINKED LIST-BASED DEQUE =====================

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

LinkedDeque* createLinkedDeque() {
    LinkedDeque* dq = (LinkedDeque*)malloc(sizeof(LinkedDeque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

bool isLinkedDequeEmpty(LinkedDeque* dq) {
    return dq->front == NULL;
}

void insertFrontLinked(LinkedDeque* dq, int data) {
    Node* newNode = createNode(data);
    
    if (isLinkedDequeEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    
    dq->size++;
    printf("Inserted %d at front (linked)\n", data);
}

void insertRearLinked(LinkedDeque* dq, int data) {
    Node* newNode = createNode(data);
    
    if (isLinkedDequeEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    
    dq->size++;
    printf("Inserted %d at rear (linked)\n", data);
}

int deleteFrontLinked(LinkedDeque* dq) {
    if (isLinkedDequeEmpty(dq)) {
        printf("Deque is empty! Cannot delete from front.\n");
        return -1;
    }
    
    Node* temp = dq->front;
    int data = temp->data;
    
    if (dq->front == dq->rear) {  // Only one element
        dq->front = dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }
    
    free(temp);
    dq->size--;
    printf("Deleted %d from front (linked)\n", data);
    return data;
}

int deleteRearLinked(LinkedDeque* dq) {
    if (isLinkedDequeEmpty(dq)) {
        printf("Deque is empty! Cannot delete from rear.\n");
        return -1;
    }
    
    Node* temp = dq->rear;
    int data = temp->data;
    
    if (dq->front == dq->rear) {  // Only one element
        dq->front = dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }
    
    free(temp);
    dq->size--;
    printf("Deleted %d from rear (linked)\n", data);
    return data;
}

void displayLinkedDeque(LinkedDeque* dq) {
    if (isLinkedDequeEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    
    printf("Linked Deque (front to rear): ");
    Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ===================== DEMO FUNCTIONS =====================

void demoArrayDeque() {
    printf("\n=== ARRAY-BASED DEQUE DEMO ===\n");
    
    ArrayDeque* dq = createArrayDeque();
    
    insertRear(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);
    insertFront(dq, 1);
    
    displayArrayDeque(dq);
    
    printf("Front element: %d\n", getFront(dq));
    printf("Rear element: %d\n", getRear(dq));
    
    deleteFront(dq);
    deleteRear(dq);
    
    displayArrayDeque(dq);
    
    free(dq);
}

void demoLinkedDeque() {
    printf("\n=== LINKED LIST-BASED DEQUE DEMO ===\n");
    
    LinkedDeque* dq = createLinkedDeque();
    
    insertRearLinked(dq, 100);
    insertRearLinked(dq, 200);
    insertFrontLinked(dq, 50);
    insertFrontLinked(dq, 25);
    
    displayLinkedDeque(dq);
    
    deleteFrontLinked(dq);
    deleteRearLinked(dq);
    
    displayLinkedDeque(dq);
    
    // Clean up memory
    while (!isLinkedDequeEmpty(dq)) {
        deleteFrontLinked(dq);
    }
    free(dq);
}

void interactiveDemo() {
    printf("\n=== INTERACTIVE DEQUE DEMO ===\n");
    ArrayDeque* dq = createArrayDeque();
    int choice, value;
    
    while (1) {
        printf("\n--- Deque Operations ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Get Front Element\n");
        printf("7. Get Rear Element\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(dq, value);
                break;
            case 3:
                deleteFront(dq);
                break;
            case 4:
                deleteRear(dq);
                break;
            case 5:
                displayArrayDeque(dq);
                break;
            case 6:
                printf("Front element: %d\n", getFront(dq));
                break;
            case 7:
                printf("Rear element: %d\n", getRear(dq));
                break;
            case 8:
                free(dq);
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    printf("DEQUE (Double-Ended Queue) Implementation\n");
    printf("=========================================\n");
    
    // Run demonstrations
    demoArrayDeque();
    demoLinkedDeque();
    
    // Interactive demo
    char runInteractive;
    printf("\nWould you like to try interactive demo? (y/n): ");
    scanf(" %c", &runInteractive);
    
    if (runInteractive == 'y' || runInteractive == 'Y') {
        interactiveDemo();
    }
    
    return 0;
}

/*
 * DEQUE CHARACTERISTICS:
 * ======================
 * 
 * OPERATIONS:
 * - insertFront(x): Add element at front
 * - insertRear(x): Add element at rear  
 * - deleteFront(): Remove element from front
 * - deleteRear(): Remove element from rear
 * - getFront(): Get front element
 * - getRear(): Get rear element
 * - isEmpty(): Check if deque is empty
 * - size(): Get number of elements
 * 
 * TIME COMPLEXITIES:
 * Array-based: All operations O(1)
 * Linked List: All operations O(1)
 * 
 * SPACE COMPLEXITY:
 * Array-based: O(n) fixed
 * Linked List: O(n) dynamic
 * 
 * APPLICATIONS:
 * - Browser history (back/forward)
 * - Undo/Redo operations
 * - Sliding window problems
 * - Palindrome checking
 * - BFS in graphs
 * - Sliding window minimum/maximum
 * - Minimum subarray sum problems
 * 
 * SLIDING WINDOW MINIMUM ALGORITHM:
 * 1. Use deque to store indices of array elements
 * 2. Maintain deque in increasing order of values
 * 3. Front of deque always contains minimum of current window
 * 4. Remove indices outside current window from front
 * 5. Remove indices with larger values from rear before inserting
 * 
 * TIME COMPLEXITY: O(n) for sliding window minimum
 * SPACE COMPLEXITY: O(k) where k is window size
 */
