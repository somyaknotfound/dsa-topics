#include<iostream>

#include<vector>
using namespace std;


void countFreq(int arr[] , int n) {
    vector<bool> visited(n, false) ;
    int maxFreq = 0 , minFreq = n;
    int maxEle = 0 , minEle = 0;



    for(int i = 0 ; i < n ; i++) {
        if (visited[i]== true) {
            continue;
        }
        int count =1 ;
        for (int j = i+1;j<n;j++){
            if (arr[i]==arr[j]) {
                visited[j] == true;
                count++;
            }

        }

        if (count>maxFreq) {
            maxFreq = count;
            maxEle = arr[i];
        }

        if (count<minFreq) {
            minFreq = count ;
            minEle = arr[i];
        }
    }
    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}





int main()
{
int arr[] = {10,5,10,15,10,5};
     int n = sizeof(arr) / sizeof(arr[0]);
     countFreq(arr,n);
return 0;

}