#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial node
typedef struct Node {
    int exponent;
    int coefficient;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int exp, int coef) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->exponent = exp;
    newNode->coefficient = coef;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in descending order of exponents
Node* insertTerm(Node* head, int exp, int coef) {
    if (coef == 0) return head; // Don't insert zero coefficient terms
    
    Node* newNode = createNode(exp, coef);
    
    // If list is empty or new term has higher exponent
    if (head == NULL || head->exponent < exp) {
        newNode->next = head;
        return newNode;
    }
    
    // If same exponent exists, add coefficients
    if (head->exponent == exp) {
        head->coefficient += coef;
        free(newNode);
        // If coefficient becomes zero, remove the node
        if (head->coefficient == 0) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
        return head;
    }
    
    // Find the correct position to insert
    Node* current = head;
    while (current->next != NULL && current->next->exponent > exp) {
        current = current->next;
    }
    
    // If same exponent found
    if (current->next != NULL && current->next->exponent == exp) {
        current->next->coefficient += coef;
        free(newNode);
        // If coefficient becomes zero, remove the node
        if (current->next->coefficient == 0) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    } else {
        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }
    
    return head;
}

// Function to read polynomial from input
Node* readPolynomial(int n) {
    Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int exp, coef;
        scanf("%d %d", &exp, &coef);
        head = insertTerm(head, exp, coef);
    }
    
    return head;
}

// Function to check if both numbers have same parity
int sameParity(int a, int b) {
    return (a % 2) == (b % 2);
}

// Function to multiply polynomials with parity filter
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    
    // Multiply each term of poly1 with each term of poly2
    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            // Only multiply if coefficients have same parity
            if (sameParity(p1->coefficient, p2->coefficient)) {
                int newExp = p1->exponent + p2->exponent;
                int newCoef = p1->coefficient * p2->coefficient;
                result = insertTerm(result, newExp, newCoef);
            }
        }
    }
    
    return result;
}

// Function to print polynomial
void printPolynomial(Node* head) {
    if (head == NULL) {
        // Print nothing for empty polynomial as specified
        return;
    }
    
    Node* current = head;
    while (current != NULL) {
        printf("%d %d", current->exponent, current->coefficient);
        current = current->next;
        if (current != NULL) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to free polynomial memory
void freePolynomial(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m;
    
    // Read first polynomial
    scanf("%d", &n);
    Node* poly1 = readPolynomial(n);
    
    // Read second polynomial
    scanf("%d", &m);
    Node* poly2 = readPolynomial(m);
    
    // Multiply polynomials with parity filter
    Node* result = multiplyPolynomials(poly1, poly2);
    
    // Print result
    printPolynomial(result);
    
    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    
    return 0;
}

/*
Example trace for given input:
First polynomial: 3x² + 2x¹
Second polynomial: 4x¹ + 5x⁰

Pairwise products:
- 3 × 4 = 12 at exponent 2 + 1 = 3 (odd×even - discard)
- 3 × 5 = 15 at exponent 2 + 0 = 2 (odd×odd - keep)
- 2 × 4 = 8 at exponent 1 + 1 = 2 (even×even - keep)  
- 2 × 5 = 10 at exponent 1 + 0 = 1 (even×odd - discard)

Combine like terms at exponent 2: 15 + 8 = 23
Result: 23x²

Time Complexity: O(n × m)
Space Complexity: O(nm) in worst case
*/
