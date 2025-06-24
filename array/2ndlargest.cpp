#include<iostream>
#include<vector>
using namespace std;

// brute force sort the array then -> make a for loop {for(int i = n-2); i>=0;i--} 
// (if(arr[i]!= largest){ secondl = arr[i]; break;)}
// worse case [1,7,7,7,7,7,7,7] - nlogn + n (also 2nd largest might not exist)

// better
// first pass o(n) largest = 1 , keep slargest = -1 -> element are you greater than slargest and are you not largest 
// time complexity o(n){no}  if(arr[i]> slargest && arr[i]!=largest)
// o(n+n);


// optimal
// largest = arr[0];
// slargest = -1; does not contain any negative numbers if it does take it as INT_MIN

int secondlargest(vector<int> &a , int n) {
    int largest = a[0];
    int slargest = -1;
    for (int i =1; i<n;i++) {
        if (a[i]>largest) {
            slargest = largest;
            largest = a[i];

        }
        else if (a[i] < largest && a[i]>slargest) {
            slargest = a[i];
        }
        
        
    }
    return slargest;


}

int secondSmallest(vector<int> &a , int n) {
    int smallest = a[0];
    int ssmalest = INT_MAX;
    for (int i = 1;i<n;i++) {
        if (a[i]<smallest) {
            ssmalest = smallest;
            smallest = a[i];
        }
        else if(a[i]>smallest && a[i]<ssmalest) {
            ssmalest = a[i];
        }
    }
    return ssmalest;
}


vector <int> getSecondOrderElements(int n, vector <int> a) {
    int slargest = secondlargest(a,n);
    int ssmallest = secondSmallest(a,n);
    return {slargest,ssmallest};
}




int main()
{
    vector<int> a = {1,2,3,4,5};
    int n = 5;
    vector<int> k = getSecondOrderElements(n,a);

    for (int i = 0 ; i<k.size();i++) {
        cout<<k[i]<<" ";
    }
    return 0;
}