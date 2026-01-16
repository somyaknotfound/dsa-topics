#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int subArraySum(vector <int> &arr , int k) {
       int n  = arr.size();
       
       int count  =0 ;
       
       for (int i = 0 ; i < n ; i++) {
           for (int j = i ; j < n ; j++) {
               int sum = 0;
               for (int k = i ; k <=j ; k ++) {
                   sum+=arr[k];
               }
               if (sum == k) {
                   count++;
               }
           }
       }
       return count;
   }
   
   int subArraySumBetter(vector <int> &arr , int k) {
       int n = arr.size();
       int count = 0;
       
       for (int i = 0  ; i < n ; i++) {
           int sum = 0;
           for (int j = i ;j < n ; j++) {
               sum+=arr[j];
               
               if (sum==k) {
                   count++;
               }
           }
       }
       return count;
   }
   
   int SubarraySumOptimal(vector <int> &arr , int k) {
       int n = arr.size();
       int count = 0;
       
       unordered_map <int,int> pfs;
       int prefixSum = 0;
       
       pfs[0] = 1;
       
       for (int i = 0  ; i< n ; i++) {
           prefixSum+=arr[i];
           
           int rem = prefixSum - k;
           
           if (pfs.find(rem) != pfs.end()) {
               count+=pfs[rem];
           }
           
           pfs[prefixSum]++;
       }
       return count;
   }
};
int main() {
    // Input array
    vector<int> arr = {3, 1, 2, 4};

    // Target sum
    int k = 6;

    // Create Solution object
    Solution sol;

    // Call function and store result
    int result = sol.SubarraySumOptimal(arr, k);

    // Print the count of subarrays
    cout << "The number of subarrays is: " << result << "\n";

    return 0;
}
