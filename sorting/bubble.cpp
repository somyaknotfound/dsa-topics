#include<iostream>
using namespace std;


void bubble_sort(int arr[], int n) {
    for (int i = n-1 ; i>=0;i--) {
        for (int j = 0 ; j<=i-1;j++) {
            int didSwap = 0;
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
            if (didSwap == 0) {
                break;
            }
        }
    }
}




int main()
{
        int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Fixed: arr[i] not arr[n]
    }
    cout << endl;
    return 0;
}