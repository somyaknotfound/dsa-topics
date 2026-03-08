#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
    int findSquareRoot(int n) {
        int ans = 0;
        
        for (int i = 1  ; i <= n ;i++) {
            if ((long long)i*i <= n) {
                ans = i;
            } else {
                break;
            }
        }
        
        return ans;
    }
    
    
    int findSqrt(int n) {
        if (n<2) return n;
        
        int left = 1 ; 
        int right = n/2;
        int ans = 0;
        
        while (left<=right) {
            long long mid = left + (right-left)/2;
            
            if (mid* mid<=n) {
                ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        return ans;
    }
    
    
    
    
    
};



int main() {
    // Example input
    int n = 27;

    // Create object of Solution
    Solution sol;

    // Call function and print result
    cout << sol.findSqrt(n) << endl;

    return 0;
}
