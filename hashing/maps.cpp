#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i =0 ; i<n;i++){
        cin>>arr[i];
    }

    // pre-compute

    map<int , int> mpp;
    for (int i = 0 ; i<n;i++) {
        mpp[arr[i]]++;
    }

    for (auto it: mpp) {
        cout<< it.first << "->" << it.second << endl;
    }


    int q ;
    cin>> q;
     while(q--) {
        int number ;
        cin>> number;
        // fetch
        cout<<mpp[number];
     }
    return 0;
}