#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // Check left neighbor if exists
            bool left = (i == 0) || (nums[i] >= nums[i - 1]);
            // Check right neighbor if exists
            bool right = (i == n - 1) || (nums[i] >= nums[i + 1]);
            
            // If both sides are valid, return index
            if (left && right) return i;
        }

        // In case no peak found (shouldn't happen)
        return -1;
    }
    
    
    
    
    int findPeakElementOptimized(vector<int>& nums) {
        int n = nums.size();

        if (n==1) return 0;

        if (nums[0] > nums[1]) return 0;

        if (nums[n-1] > nums[n-2]) return n-1;

        int l = 1;
        int h = n-2;

        while (l<=h) {
            int mid = l+(h-l)/2;

            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                return mid;
            }

            else if (nums[mid] > nums[mid-1]) {
                l = mid +1;
            }

            else  {
                h = mid-1;
            }
        }
        return -1;
    }
};



int main() {
    Solution sol;
    vector<int> nums = {1, 3, 20, 4, 1, 0};
    int index = sol.findPeakElement(nums);
    cout << "Peak at index: " << index << " with value: " << nums[index] << endl;
    return 0;
}
