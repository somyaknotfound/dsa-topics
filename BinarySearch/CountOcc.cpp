#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int countOcc(vector <int> &v , int k) {
        int n = v.size();
        int c = 0;
        for (int i = 0 ; i < n ; i++) {
            if (v[i] == k) {
                c++;
            }
        }
        
        return c;
    }
    
    int countOccOptimized(vector <int> &v, int key) {
        int l  = 0;
        int h = v.size()  -1;
        int f = -1;
        int e = -1;
        
        while (l<=h) {
            int mid = l + (h-l)/2;
            
            if (key == v[mid]) {
                f = mid;
                h = mid -1;
            } else if (key < v[mid]) {
                h = mid -1;
            } else {
                l = mid+1;
            }
        }
        
        l = 0;
        h = v.size() - 1;

        
        while (l<=h) {
            int mid = l + (h-l)/2;
            
            if (key == v[mid]) {
                e = mid;
                l = mid + 1;
            } else if (key < v[mid]) {
                h = mid -1;
            } else {
                l = mid+1;
            }
        }
        
        return e-f+1;
        
        
    }
};


int main() {
 
  
 {
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    Solution sol;
    int ans = sol.countOccOptimized(arr , x) ;
    cout << "The number of occurrences is: "
         << ans << "\n";
    return 0;
}

}
