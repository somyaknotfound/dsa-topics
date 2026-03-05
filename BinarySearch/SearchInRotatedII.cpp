#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    bool rotatedSearchII(vector <int> &v , int k) {
        int n = v.size();
        int l = 0;
        int h = n-1;
        bool flag = false;
        
        for (int i = 0 ; i < n ; i++) {
            if (v[i] == k) {
                flag = true;
                break;
            }
        }
        
        return flag;
    }
    
    bool rotatedSearchIIOptimized( vector <int> &arr , int target) {
        int high = arr.size()  -1; 
        int low = 0;
        
        bool flag = false;
        
        while (low<=high) {
            int mid = low + (high-low)/2;
            
            if (arr[mid] == target) {
                flag = true;
                break;
                
            }
            
            if (arr[low] == arr[mid] && arr[mid] == arr[high] ) {
                low++;
                high--;
                continue;
            }
            
            if (arr[low]<=arr[mid]) {
                // left half is sorted look for target in left half
                if (arr[low]<=target && target <=arr[mid]) {
                    // trim down the right half
                    high = mid-1;
                } else {
                    // regular method-1 on left half
                    low = mid+1;
                } } else {
                    // right half sorted search in right half
                    if (arr[mid]<= target && target <= arr[high]) {
                        low = mid+1;
                        // cut left half
                        
                    } else {
                        high = mid-1;
                    }
                }
            
            
        }
        
        return flag;
        
    }
};


int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;

    // Create object of Solution class
    Solution obj;
    bool ans = obj.rotatedSearchIIOptimized(arr, k);

    // Print result
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}
