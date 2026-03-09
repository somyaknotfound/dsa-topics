#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int nthRoot(int n , int m) {
        for (int i = 0 ; i <= m ; i++) {
            long long power = pow(i , n);
            if (power == m) return i;
            if (power > m) break;
            
        }
        return -1;
        
    }
    
    int nthRootBS(int n , int m) {
        int low = 1;
        int high = m;
        
        while (low <=high) {
            int mid = low + (high-low)/2;
            
            long long ans = 1;
            for (int i = 0 ; i < n ;i++) {
                ans*=mid;
                if (ans > m) break;
            }
            
            if (ans == m) return mid;
            
            if (ans < m) low = mid+1;
            else high = mid-1;
            
            
            
            
        }
        return -1;
    }
};


int main() {
    Solution sol;
    int n = 6, m = 64;

    // Find nth root
    cout << "Nth Root: " << sol.nthRootBS(n, m) << endl;

    return 0;
}
