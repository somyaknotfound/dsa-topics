#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node of a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// A structure to represent a Min Heap Node
// It holds a pointer to a linked list node
struct MinHeapNode {
    struct Node* node;
};

// A structure to represent a Min Heap
struct MinHeap {
    struct MinHeapNode* harr; // Array of MinHeapNodes
    int heap_size; // Current number of elements in min heap
    int capacity; // Maximum possible size of min heap
};

// Function to create a new linked list node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        perror("Failed to allocate memory for a new node");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print a linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// A standard function to heapify a subtree with the root at given index
// This function assumes that the subtrees are already heapified
void MinHeapify(struct MinHeap* minHeap, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < minHeap->heap_size && minHeap->harr[l].node->data < minHeap->harr[smallest].node->data) {
        smallest = l;
    }

    if (r < minHeap->heap_size && minHeap->harr[r].node->data < minHeap->harr[smallest].node->data) {
        smallest = r;
    }

    if (smallest != i) {
        // Swap nodes
        struct MinHeapNode temp = minHeap->harr[i];
        minHeap->harr[i] = minHeap->harr[smallest];
        minHeap->harr[smallest] = temp;
        // Recursively heapify the affected sub-tree
        MinHeapify(minHeap, smallest);
    }
}

// Function to create a min heap of given capacity
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    if (minHeap == NULL) {
        perror("Failed to allocate memory for min heap");
        exit(EXIT_FAILURE);
    }
    minHeap->heap_size = 0;
    minHeap->capacity = capacity;
    minHeap->harr = (struct MinHeapNode*)malloc(capacity * sizeof(struct MinHeapNode));
    if (minHeap->harr == NULL) {
        perror("Failed to allocate memory for heap array");
        exit(EXIT_FAILURE);
    }
    return minHeap;
}

// Function to extract the minimum node from the min heap
struct MinHeapNode extractMin(struct MinHeap* minHeap) {
    if (minHeap->heap_size <= 0) {
        // Return an empty node if heap is empty
        struct MinHeapNode empty_node = { NULL };
        return empty_node;
    }

    struct MinHeapNode root = minHeap->harr[0];
    minHeap->heap_size--;

    if (minHeap->heap_size > 0) {
        minHeap->harr[0] = minHeap->harr[minHeap->heap_size];
        MinHeapify(minHeap, 0);
    }
    return root;
}

// Function to insert a new node into the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode node) {
    if (minHeap->heap_size == minHeap->capacity) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    minHeap->heap_size++;
    int i = minHeap->heap_size - 1;
    minHeap->harr[i] = node;

    // Fix the min heap property if it is violated
    while (i != 0 && minHeap->harr[(i - 1) / 2].node->data > minHeap->harr[i].node->data) {
        struct MinHeapNode temp = minHeap->harr[i];
        minHeap->harr[i] = minHeap->harr[(i - 1) / 2];
        minHeap->harr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to merge k sorted linked lists
struct Node* mergeKLists(struct Node* arr[], int k) {
    struct Node* head = NULL;
    struct Node* last = NULL;

    // Create a min heap of size k
    struct MinHeap* minHeap = createMinHeap(k);

    // Insert the first node of each list into the min heap
    for (int i = 0; i < k; i++) {
        if (arr[i] != NULL) {
            struct MinHeapNode temp = { arr[i] };
            insertMinHeap(minHeap, temp);
        }
    }

    // Process the min heap
    while (minHeap->heap_size > 0) {
        // Extract the minimum node from the heap
        struct MinHeapNode min_node = extractMin(minHeap);

        // Append the minimum node to the result list
        if (head == NULL) {
            head = last = min_node.node;
        } else {
            last->next = min_node.node;
            last = min_node.node;
        }

        // If the extracted node has a next node, insert it into the heap
        if (min_node.node->next != NULL) {
            struct MinHeapNode next_node = { min_node.node->next };
            insertMinHeap(minHeap, next_node);
        }
    }

    // Free the memory allocated for the min heap
    free(minHeap->harr);
    free(minHeap);
    
    return head;
}

// Driver code
int main() {
    int k = 3; // Number of linked lists
    
    // An array of k linked lists
    struct Node* arr[k];

    // List 1: 1 -> 4 -> 5
    arr[0] = newNode(1);
    arr[0]->next = newNode(4);
    arr[0]->next->next = newNode(5);

    // List 2: 1 -> 3 -> 4
    arr[1] = newNode(1);
    arr[1]->next = newNode(3);
    arr[1]->next->next = newNode(4);

    // List 3: 2 -> 6
    arr[2] = newNode(2);
    arr[2]->next = newNode(6);

    printf("Original lists:\n");
    for (int i = 0; i < k; i++) {
        printf("List %d: ", i + 1);
        printList(arr[i]);
    }

    // Merge the lists
    struct Node* merged_list = mergeKLists(arr, k);

    printf("\nMerged linked list:\n");
    printList(merged_list);

    // Free memory for the linked lists
    struct Node* current = merged_list;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
