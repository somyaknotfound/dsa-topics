#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int MinimumInARotatedSoted(vector <int> &v) {
        int n = v.size();
        int mini = INT_MAX;
        for (int i = 0 ; i < n ; i++) {
            if (v[i]<mini) {
                mini = v[i];
            }
        }
        
        return mini;
        
        
    }
    
    int FindMinOptimized(vector <int> &a) {
        int l = 0;
        int h = a.size()-1;
        int ans = INT_MAX;
        while (l<=h) {
            int mid = l + (h-l)/2;
            
            if (a[l]<=a[mid]) {
                // left half sorted
                ans = min(a[l] , ans);
                l = mid+1;
            } else {
                ans = min(a[mid] , ans);
                h = mid-1;
            }
        }
        return ans;
    }
};


int main() {

    // Input array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Create object of Solution
    Solution sol;

    // Call function and store result
    int result = sol.FindMinOptimized(nums);

    // Output the result
    cout << "Minimum element is " << result << endl;

    return 0;
}
