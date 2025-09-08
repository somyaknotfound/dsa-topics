#include <stdio.h>

// Function to solve Tower of Hanoi problem
// n: number of disks
// source: source rod (A, B, or C)
// destination: destination rod (A, B, or C)
// auxiliary: auxiliary rod (A, B, or C)
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: if only one disk, move it directly
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    
    // Step 1: Move n-1 disks from source to auxiliary rod
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Step 2: Move the largest disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    
    // Step 3: Move n-1 disks from auxiliary to destination rod
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Function to count total number of moves
int countMoves(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * countMoves(n - 1) + 1;
}

// Alternative counting function using formula
int totalMoves(int n) {
    // Formula: 2^n - 1
    int moves = 1;
    for (int i = 0; i < n; i++) {
        moves *= 2;
    }
    return moves - 1;
}

int main() {
    int n;
    
    printf("Tower of Hanoi Problem\n");
    printf("======================\n");
    printf("Enter number of disks: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive number of disks.\n");
        return 1;
    }
    
    printf("\nSolution for %d disks:\n", n);
    printf("Rods: A (source), B (auxiliary), C (destination)\n\n");
    
    // Solve the problem
    towerOfHanoi(n, 'A', 'C', 'B');
    
    // Display total moves
    printf("\nTotal number of moves: %d\n", totalMoves(n));
    
    // Verify with counting function
    printf("Verification (recursive count): %d\n", countMoves(n));
    
    return 0;
}

/* 
 * ALGORITHM EXPLANATION:
 * ======================
 * 
 * To move n disks from source to destination:
 * 1. Move n-1 disks from source to auxiliary rod
 * 2. Move the largest disk from source to destination
 * 3. Move n-1 disks from auxiliary to destination
 * 
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) - due to recursion stack
 * 
 * The minimum number of moves required is always 2^n - 1
 * 
 * Example for n=3:
 * Move disk 1 from rod A to rod C
 * Move disk 2 from rod A to rod B
 * Move disk 1 from rod C to rod B
 * Move disk 3 from rod A to rod C
 * Move disk 1 from rod B to rod A
 * Move disk 2 from rod B to rod C
 * Move disk 1 from rod A to rod C
 * 
 * Total moves: 7 (which is 2^3 - 1)
 */
