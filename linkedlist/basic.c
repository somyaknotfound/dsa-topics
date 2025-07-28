#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning (corrected spelling)
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    newNode->next = head;
    return newNode;
}

// Insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert at a specific position (0-indexed)
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete from beginning (corrected spelling)
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete from a specific position (0-indexed)
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (position < 0) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 0) {
        return deleteFromBeginning(head);
    }
    
    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Delete by value (first occurrence)
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("Value %d not found in the list!\n", value);
        return head;
    }
    
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Search for a value
int search(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 0;
    
    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Not found
}

// Get length of the list
int getLength(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Reverse the list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Free the entire list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Get element at a specific position
int getElement(struct Node* head, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return -1;
    }
    
    struct Node* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return -1;
    }
    
    return temp->data;
}

// Main function with example usage
int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    printf("Linked List Implementation in C\n");
    printf("================================\n\n");
    
    while (1) {
        printf("\nOperations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Delete by value\n");
        printf("8. Search\n");
        printf("9. Display\n");
        printf("10. Get length\n");
        printf("11. Reverse\n");
        printf("12. Get element at position\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
                
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
                
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
                
            case 4:
                head = deleteFromBeginning(head);
                break;
                
            case 5:
                head = deleteFromEnd(head);
                break;
                
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
                
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                head = deleteByValue(head, data);
                break;
                
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &data);
                position = search(head, data);
                if (position != -1) {
                    printf("Value %d found at position %d\n", data, position);
                } else {
                    printf("Value %d not found in the list\n", data);
                }
                break;
                
            case 9:
                display(head);
                break;
                
            case 10:
                printf("Length of the list: %d\n", getLength(head));
                break;
                
            case 11:
                head = reverse(head);
                printf("List reversed successfully!\n");
                break;
                
            case 12:
                printf("Enter position: ");
                scanf("%d", &position);
                data = getElement(head, position);
                if (data != -1) {
                    printf("Element at position %d: %d\n", position, data);
                }
                break;
                
            case 13:
                freeList(head);
                printf("Exiting program. Memory freed.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}