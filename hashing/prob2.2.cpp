#include<iostream>
#include<unordered_map>
using namespace std;


void frequency(int arr[], int n) {

    unordered_map<int , int> map;

    for (int  i = 0; i< n ;i++) {
        map[arr[i]]++;
    }

    int maxFreq = 0 , minFreq = n;
    int maxele = 0 , minele = 0;

    for (auto it: map) {
        int count = it.second;
        int element = it.first;

        if (count>maxFreq) {
            maxele = element;
            maxFreq = count;
        }

        if (count<minFreq) {
            minele = element;
            minFreq = count;
        }
    }
    cout << "The highest frequency element is: " << maxele << "\n";
    cout << "The lowest frequency element is: " << minele << "\n";
    
}



int main()
{
    int arr[] = {10,5,10,15,10,5};
     int n = sizeof(arr) / sizeof(arr[0]);
     frequency(arr,n);
    return 0;


}