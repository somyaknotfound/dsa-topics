#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    
    int missingKBrute(vector <int> &a  ,int k) {
        for (int i = 0 ;i< a.size() ;i++) {
            if (a[i] <= k) {
                k++;
            } else {
                break;
            }
        }
        
        return k;
    }
    
    int missingKOptimal(vector <int> &a , int k) {
        int low = 0 ;
        int high = a.size()  - 1;
        
        while (low <= high) {
            int mid  = low + (high-low)/2;
            int missing = a[mid] - (mid+1);
            
            if (missing < k) {
                low  =mid  +1;
                
            } else {
                high = mid - 1;
            }
        }
        
        return high + k +1;
    }
};



int main() {
    vector<int> vec = {4, 7, 9, 10};  // Sorted array
    int n = vec.size();              // Size of array
    int k = 4;                       // k-th missing number to find
    Solution sol;
    int ans = sol.missingKOptimal(vec,k);
    cout << ans <<endl;
}
