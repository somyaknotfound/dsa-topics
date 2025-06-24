#include<iostream>
#include<vector>
using namespace std;

int largerstELement(vector<int> &arr , int n)  {
    int largest = arr[0]; 
    for (int i = 0 ;i < n ; i++) {
        if (arr[i]>largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    vector<int> arr = {4,3,6,5,17,2};
    int k = 6;
    int l = largerstELement(arr, k);
    cout<< l<< endl;

    return 0;
}