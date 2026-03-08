#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
    int SingleNumberSortedArr(vector <int> &a) {
        int n = a.size();
        
        if (n==1) return a[0];
        
        
        for (int i = 0 ; i < n ; i++) {
            if (i == 0) {
                if (a[i] != a[i+1]) {
                    return a[i];
                }
            }
            else if (i == n-1) {
                if (a[i-1] != a[i]) {
                    return a[i];
                }
            } else {
                if (a[i]!= a[i-1] && a[i] != a[i+1]) {
                    return a[i];
                }
            }
        }
        
        
        return -1;
    }
    
    
    int singleNonDuplicate(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Initialize the result variable with 0
        int ans = 0;

        // Traverse the array and XOR all elements
        for (int i = 0; i < n; i++) {
            ans = ans ^ arr[i];
        }

        // Return the unique element found using XOR
        return ans;
    }
    
    int Optimal(vector <int> &v) {
        int n  = v.size();
        
        if (n==1) return v[0];
        
        
        if (v[0] != v[1]) return v[0];
        if (v[n-1] != v[n-2]) return v[n-1];
        
        int l = 1;
        int h = n-2;
        
        
        while (l<=h) {
            int mid = l + (h-l)/2;
            
            
            if (v[mid]!= v[mid+1] && v[mid] != v[mid-1]) {
                return v[mid];
            }
            
            else if (mid %2 ==1 && v[mid] == v[mid-1] || mid%2 == 0 && v[mid] == v[mid+1]) {
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        
        return -1;
    }
};



int main() {
    // Input array with one unique element
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Create an object of Solution class
    Solution obj;

    // Call the function and store result
    int ans = obj.Optimal(arr);

    // Print the result
    cout << "The single element is: " << ans << "\n";

    return 0;
}
