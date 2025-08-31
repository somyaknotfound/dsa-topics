#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct QueueNode {
    struct TreeNode* treeNode;
    struct TreeNode* parent;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, struct TreeNode* node, struct TreeNode* parent) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->parent = parent;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

QueueNode* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    q->size--;
    return temp;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

struct TreeNode* findStartNode(struct TreeNode* root, int start, struct TreeNode* parent, struct TreeNode** parents, int* nodeCount) {
    if (root == NULL) return NULL;
    
    parents[*nodeCount] = parent;
    (*nodeCount)++;
    
    if (root->val == start) {
        return root;
    }
    
    struct TreeNode* leftResult = findStartNode(root->left, start, root, parents, nodeCount);
    if (leftResult != NULL) return leftResult;
    
    return findStartNode(root->right, start, root, parents, nodeCount);
}

struct TreeNode* getParent(struct TreeNode* root, struct TreeNode* target, struct TreeNode* parent) {
    if (root == NULL) return NULL;
    if (root == target) return parent;
    
    struct TreeNode* leftParent = getParent(root->left, target, root);
    if (leftParent != NULL) return leftParent;
    
    return getParent(root->right, target, root);
}

int amountOfTime(struct TreeNode* root, int start) {
    if (root == NULL) return 0;
    
    struct TreeNode* startNode = NULL;
    
    struct TreeNode* findNode(struct TreeNode* node, int val) {
        if (node == NULL) return NULL;
        if (node->val == val) return node;
        
        struct TreeNode* left = findNode(node->left, val);
        if (left != NULL) return left;
        
        return findNode(node->right, val);
    }
    
    startNode = findNode(root, start);
    if (startNode == NULL) return 0;
    
    Queue* currentLevel = createQueue();
    Queue* nextLevel = createQueue();
    
    bool visited[100001] = {false};
    
    struct TreeNode* visitedNodes[100000];
    int visitedCount = 0;
    
    void markVisited(struct TreeNode* node) {
        visitedNodes[visitedCount++] = node;
    }
    
    bool isVisited(struct TreeNode* node) {
        for (int i = 0; i < visitedCount; i++) {
            if (visitedNodes[i] == node) return true;
        }
        return false;
    }
    
    enqueue(currentLevel, startNode, NULL);
    markVisited(startNode);
    
    int time = 0;
    
    while (!isEmpty(currentLevel)) {
        while (!isEmpty(currentLevel)) {
            QueueNode* current = dequeue(currentLevel);
            struct TreeNode* node = current->treeNode;
            
            struct TreeNode* parent = getParent(root, node, NULL);
            
            if (node->left != NULL && !isVisited(node->left)) {
                enqueue(nextLevel, node->left, node);
                markVisited(node->left);
            }
            
            if (node->right != NULL && !isVisited(node->right)) {
                enqueue(nextLevel, node->right, node);
                markVisited(node->right);
            }
            
            if (parent != NULL && !isVisited(parent)) {
                enqueue(nextLevel, parent, NULL);
                markVisited(parent);
            }
            
            free(current);
        }
        
        if (!isEmpty(nextLevel)) {
            time++;
            Queue* temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;
        }
    }
    
    free(currentLevel);
    free(nextLevel);
    
    return time;
}

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = createNode(10);
    root->right = createNode(30);
    root->right->right = createNode(50);
    root->right->right->right = createNode(70);
    root->left = createNode(20);
    root->left->left = createNode(40);
    root->left->left->left = createNode(60);
    
    
    int start = 20;
    int result = amountOfTime(root, start);
    
    printf("Time for entire forest to burn: %d minutes\n", result);
    
    return 0;
}