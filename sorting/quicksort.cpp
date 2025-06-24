#include<iostream>
using namespace std;


int f(int arr[], int low , int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j) {
        while (arr[i]<= pivot && i<=high) {
            i++;
        }
        while(arr[j]>=pivot && j>=low) {
            j--;
        }

        if (i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] =temp;
        }
    }

    int t = arr[low];
    arr[low] = arr[j];
    arr[j] = t;
    return j;
}



void qs(int arr[], int low , int high) {
    if (low<high) {
        int pindex = f(arr, low ,high);
        qs(arr,low,pindex-1);
        qs(arr,pindex+1,high);
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
    qs(arr, 0 , n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Fixed: arr[i] not arr[n]
    }
    cout << endl;
    return 0;

}