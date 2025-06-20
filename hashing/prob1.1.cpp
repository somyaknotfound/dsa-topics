// given an array find the number of occurences of each element in the array

// double for loop



#include<iostream>
#include<vector>
using namespace std;

void CountFreq(int arr[], int n) {
    vector<bool> visited(n, false);

    for (int i = 0 ; i< n ;i++) {
        if (visited[i]== true) {
            continue;
        }
        int count = 1;
        for (int j =i+1 ;j<n ;j++ ){
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        } 
        cout << arr[i] << " "<< count << endl;
    }
}


int main()
{
     int arr[] = {10,5,10,15,10,5};
     int n = sizeof(arr) / sizeof(arr[0]);
     CountFreq(arr,n);
return 0;
}