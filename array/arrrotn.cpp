#include<iostream>
#include<vector>
using namespace std;

void leftrotnby1(vector <int> &arr) {
    int temp = arr[0];
    for (int i = 1 ; i< arr.size() ; i++) {
        arr[i-1] = arr[i];
    }
    arr[arr.size()-1] = temp;
}

int main()
{

    return 0;
}