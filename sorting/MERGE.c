#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    // Create temporary arrays
    int* left = (int*)malloc(n1 * sizeof(int));
    int* right = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[low..high]
    int i = 0, j = 0, k = low;
    
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements from left array
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    // Copy remaining elements from right array
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
    // Free allocated memory
    free(left);
    free(right);
}

void mS(int arr[], int low, int high) {
    if (low >= high) return;  // Base case
    
    int mid = low + (high - low) / 2;  // Prevents overflow
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(int arr[], int n) {
    mS(arr, 0, n - 1);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}
