#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int rotatedSearch(vector <int> &v , int k) {
        int n = v.size();
        int res = -1;
        for (int i = 0 ;i < n ;i++) {
            if (v[i] == k) {
                res = i;
                break;
            }
        }
        return res;
    }
    
    int rotatedSearchOptimized( vector <int> &arr , int key) {
        int low = 0;
        int high = arr.size() - 1;
        
        
        int res = -1;
        
        while (low<=high) {
            int mid = low + (high-low)/2;
            
            if (arr[mid] == key) {
                res = mid;
            }
            
            if (arr[low]<=arr[mid]) {
                if (arr[low]<=key && key <= arr[mid]) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            } else {
                if (arr[mid]<= key && key <= arr[high]) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        
        return res;
        
    }
};


int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    Solution obj;
    int index = obj.rotatedSearchOptimized(nums, target);

    cout << index << endl;

    return 0;
}
