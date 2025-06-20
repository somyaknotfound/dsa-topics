#include<iostream>
using namespace std;

void selection_sort(int arr[], int n) {
    for (int i = 0; i <= n-2; i++) {
        int min_idx = i;  // Store INDEX, not value
        for (int j = i+1; j <= n-1; j++) {
            if (arr[j] < arr[min_idx]) {  // Compare with arr[min_idx]
                min_idx = j;
            }
        }
        // Swap OUTSIDE the inner loop
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}







int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selection_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Fixed: arr[i] not arr[n]
    }
    cout << endl;
    return 0;
}