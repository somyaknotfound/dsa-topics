#include <stdio.h>
#include <stdlib.h>

// Method 1: Brute Force - O(n^2) Time Complexity
long long inversionCountBruteForce(int arr[], int n) {
    long long invCount = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }
    }
    
    return invCount;
}

// Method 2: Merge Sort Based - O(n log n) Time Complexity
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long invCount = 0;
    
    // Merge the two halves while counting inversions
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // All elements from arr[i] to arr[mid-1] are greater than arr[j]
            // So there are (mid - i) inversions
            invCount += (mid - i);
        }
    }
    
    // Copy remaining elements
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    
    // Copy merged elements back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return invCount;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid + 1, right);
    }
    return invCount;
}

long long inversionCountOptimized(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    long long result = mergeSort(arr, temp, 0, n - 1);
    free(temp);
    return result;
}

// Function to print array (for debugging)
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to create a copy of array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    int n;
    
    printf("Inversion Count in Array\n");
    printf("========================\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > 500000) {
        printf("Please enter a valid number of elements (1 to 500000).\n");
        return 1;
    }
    
    int* arr = (int*)malloc(n * sizeof(int));
    int* arrCopy = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Create a copy for the optimized method (since merge sort modifies array)
    copyArray(arr, arrCopy, n);
    
    printf("\nInput Array: ");
    printArray(arr, n);
    
    // Method 1: Brute Force (for small arrays)
    if (n <= 1000) {
        long long invCount1 = inversionCountBruteForce(arr, n);
        printf("Inversion Count (Brute Force): %lld\n", invCount1);
    } else {
        printf("Brute Force skipped for large input (n > 1000)\n");
    }
    
    // Method 2: Optimized using Merge Sort
    long long invCount2 = inversionCountOptimized(arrCopy, n);
    printf("Inversion Count (Optimized): %lld\n", invCount2);
    
    // Show some example inversions for small arrays
    if (n <= 10) {
        printf("\nInversion pairs:\n");
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    printf("(%d, %d) at indices (%d, %d)\n", arr[i], arr[j], i, j);
                }
            }
        }
    }
    
    free(arr);
    free(arrCopy);
    
    return 0;
}

/* 
 * ALGORITHM EXPLANATION:
 * ======================
 * 
 * METHOD 1: BRUTE FORCE
 * - Check every pair (i,j) where i < j
 * - Count pairs where arr[i] > arr[j]
 * - Time: O(n²), Space: O(1)
 * 
 * METHOD 2: MERGE SORT BASED (OPTIMAL)
 * - During merge step of merge sort, count inversions
 * - When element from right array is smaller, it forms inversions
 *   with all remaining elements in left array
 * - Time: O(n log n), Space: O(n)
 * 
 * EXAMPLES:
 * Array: [2, 4, 1, 3, 5]
 * Inversions: (2,1), (4,1), (4,3) = 3 total
 * 
 * Array: [5, 4, 3, 2, 1] (reverse sorted)
 * Inversions: 5+4+3+2 = 14 total (maximum possible)
 * 
 * Array: [1, 2, 3, 4, 5] (sorted)
 * Inversions: 0 (minimum possible)
 */
