#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// ====================== TREE NODE STRUCTURE ======================

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Queue structure for level order traversal
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// ====================== UTILITY FUNCTIONS ======================

// Create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue operations for level order traversal
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, TreeNode* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) return NULL;
    
    QueueNode* temp = queue->front;
    TreeNode* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return treeNode;
}

// ====================== BASIC TREE OPERATIONS ======================

// Insert in Binary Tree (level order insertion)
TreeNode* insertBinaryTree(TreeNode* root, int data) {
    TreeNode* newNode = createNode(data);
    
    if (root == NULL) {
        return newNode;
    }
    
    Queue* queue = createQueue();
    enqueue(queue, root);
    
    while (!isQueueEmpty(queue)) {
        TreeNode* current = dequeue(queue);
        
        if (current->left == NULL) {
            current->left = newNode;
            free(queue);
            return root;
        } else {
            enqueue(queue, current->left);
        }
        
        if (current->right == NULL) {
            current->right = newNode;
            free(queue);
            return root;
        } else {
            enqueue(queue, current->right);
        }
    }
    
    free(queue);
    return root;
}

// Insert in Binary Search Tree
TreeNode* insertBST(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }
    // Equal values are ignored in BST
    
    return root;
}

// Search in Binary Search Tree
TreeNode* searchBST(TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return searchBST(root->left, key);
    }
    
    return searchBST(root->right, key);
}

// Find minimum value node (leftmost node in BST)
TreeNode* findMin(TreeNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete node in BST
TreeNode* deleteBST(TreeNode* root, int key) {
    if (root == NULL) return root;
    
    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

// ====================== TREE TRAVERSALS ======================

// Inorder traversal (Left, Root, Right)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Level order traversal (Breadth-First)
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    Queue* queue = createQueue();
    enqueue(queue, root);
    
    while (!isQueueEmpty(queue)) {
        TreeNode* current = dequeue(queue);
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
    
    free(queue);
}

// ====================== TREE PROPERTIES ======================

// Calculate height of tree
int height(TreeNode* root) {
    if (root == NULL) return -1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Count total nodes
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeaves(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Check if tree is balanced
bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return abs(leftHeight - rightHeight) <= 1 && 
           isBalanced(root->left) && 
           isBalanced(root->right);
}

// Validate Binary Search Tree
bool validateBST(TreeNode* root, int minVal, int maxVal) {
    if (root == NULL) return true;
    
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }
    
    return validateBST(root->left, minVal, root->data) && 
           validateBST(root->right, root->data, maxVal);
}

bool isBST(TreeNode* root) {
    return validateBST(root, INT_MIN, INT_MAX);
}

// ====================== TREE PROBLEMS ======================

// Problem 1: Find maximum element in binary tree
int findMax(TreeNode* root) {
    if (root == NULL) return INT_MIN;
    
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int currentMax = root->data;
    
    if (leftMax > currentMax) currentMax = leftMax;
    if (rightMax > currentMax) currentMax = rightMax;
    
    return currentMax;
}

// Problem 2: Find diameter of binary tree
int diameterHelper(TreeNode* root, int* maxDiameter) {
    if (root == NULL) return 0;
    
    int leftHeight = diameterHelper(root->left, maxDiameter);
    int rightHeight = diameterHelper(root->right, maxDiameter);
    
    int currentDiameter = leftHeight + rightHeight;
    if (currentDiameter > *maxDiameter) {
        *maxDiameter = currentDiameter;
    }
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int diameter(TreeNode* root) {
    int maxDiameter = 0;
    diameterHelper(root, &maxDiameter);
    return maxDiameter;
}

// Problem 3: Lowest Common Ancestor in BST
TreeNode* lowestCommonAncestorBST(TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;
    
    if (p < root->data && q < root->data) {
        return lowestCommonAncestorBST(root->left, p, q);
    }
    if (p > root->data && q > root->data) {
        return lowestCommonAncestorBST(root->right, p, q);
    }
    
    return root;
}

// Problem 4: Path sum - check if there exists a path with given sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == NULL) return false;
    
    if (root->left == NULL && root->right == NULL) {
        return targetSum == root->data;
    }
    
    int remainingSum = targetSum - root->data;
    return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
}

// Problem 5: Mirror/Invert binary tree
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return NULL;
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

// Problem 6: Check if two trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    
    return (root1->data == root2->data) && 
           areIdentical(root1->left, root2->left) && 
           areIdentical(root1->right, root2->right);
}

// Problem 7: Print nodes at distance k from root
void printNodesAtDistance(TreeNode* root, int k) {
    if (root == NULL) return;
    
    if (k == 0) {
        printf("%d ", root->data);
        return;
    }
    
    printNodesAtDistance(root->left, k - 1);
    printNodesAtDistance(root->right, k - 1);
}

// Problem 8: Convert BST to sorted array (inorder)
void bstToArray(TreeNode* root, int* arr, int* index) {
    if (root != NULL) {
        bstToArray(root->left, arr, index);
        arr[(*index)++] = root->data;
        bstToArray(root->right, arr, index);
    }
}

// Problem 9: Print tree structure (visual representation)
void printTree(TreeNode* root, int space) {
    const int COUNT = 10;
    if (root == NULL) return;
    
    space += COUNT;
    printTree(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    printTree(root->left, space);
}

// ====================== DEMO AND TESTS ======================

TreeNode* createSampleBST() {
    TreeNode* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        root = insertBST(root, values[i]);
    }
    
    return root;
}

TreeNode* createSampleBinaryTree() {
    TreeNode* root = NULL;
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        root = insertBinaryTree(root, values[i]);
    }
    
    return root;
}

void demonstrateTraversals() {
    printf("\n=== TREE TRAVERSALS DEMO ===\n");
    TreeNode* bst = createSampleBST();
    
    printf("BST Structure:\n");
    printTree(bst, 0);
    
    printf("\nInorder (Left-Root-Right): ");
    inorderTraversal(bst);
    
    printf("\nPreorder (Root-Left-Right): ");
    preorderTraversal(bst);
    
    printf("\nPostorder (Left-Right-Root): ");
    postorderTraversal(bst);
    
    printf("\nLevel Order (BFS): ");
    levelOrderTraversal(bst);
    printf("\n");
}

void demonstrateBSTOperations() {
    printf("\n=== BST OPERATIONS DEMO ===\n");
    TreeNode* bst = NULL;
    
    printf("Inserting: 50, 30, 70, 20, 40, 60, 80\n");
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        bst = insertBST(bst, values[i]);
    }
    
    printf("Inorder traversal: ");
    inorderTraversal(bst);
    printf("\n");
    
    printf("Searching for 40: %s\n", searchBST(bst, 40) ? "Found" : "Not Found");
    printf("Searching for 90: %s\n", searchBST(bst, 90) ? "Found" : "Not Found");
    
    printf("Deleting 20 (leaf node)\n");
    bst = deleteBST(bst, 20);
    printf("Inorder after deletion: ");
    inorderTraversal(bst);
    printf("\n");
    
    printf("Deleting 50 (node with two children)\n");
    bst = deleteBST(bst, 50);
    printf("Inorder after deletion: ");
    inorderTraversal(bst);
    printf("\n");
}

void demonstrateTreeProperties() {
    printf("\n=== TREE PROPERTIES DEMO ===\n");
    TreeNode* bst = createSampleBST();
    
    printf("Tree height: %d\n", height(bst));
    printf("Total nodes: %d\n", countNodes(bst));
    printf("Leaf nodes: %d\n", countLeaves(bst));
    printf("Is balanced: %s\n", isBalanced(bst) ? "Yes" : "No");
    printf("Is valid BST: %s\n", isBST(bst) ? "Yes" : "No");
    printf("Maximum element: %d\n", findMax(bst));
    printf("Diameter: %d\n", diameter(bst));
}

void demonstrateTreeProblems() {
    printf("\n=== TREE PROBLEMS DEMO ===\n");
    TreeNode* bst = createSampleBST();
    
    // Path sum
    printf("Has path sum 155 (50+30+40+35): %s\n", 
           hasPathSum(bst, 155) ? "Yes" : "No");
    
    // LCA in BST
    TreeNode* lca = lowestCommonAncestorBST(bst, 20, 40);
    printf("LCA of 20 and 40: %d\n", lca ? lca->data : -1);
    
    // Nodes at distance
    printf("Nodes at distance 2 from root: ");
    printNodesAtDistance(bst, 2);
    printf("\n");
    
    // Convert BST to sorted array
    int arr[100];
    int index = 0;
    bstToArray(bst, arr, &index);
    printf("BST as sorted array: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Invert tree
    printf("Inverting tree...\n");
    invertTree(bst);
    printf("Inorder after inversion: ");
    inorderTraversal(bst);
    printf("\n");
}

int main() {
    demonstrateTraversals();
    demonstrateBSTOperations();
    demonstrateTreeProperties();
    demonstrateTreeProblems();
    
    printf("\n=== COMPLEXITY ANALYSIS ===\n");
    printf("BST Operations (Average Case):\n");
    printf("  Search/Insert/Delete: O(log n)\n");
    printf("BST Operations (Worst Case - Skewed Tree):\n");
    printf("  Search/Insert/Delete: O(n)\n");
    printf("Tree Traversals: O(n)\n");
    printf("Space Complexity: O(h) for recursion stack, where h is height\n");
    
    return 0;
}
