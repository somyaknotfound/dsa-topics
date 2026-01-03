#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector <int> &a) {
            int index = -1;
            for (int i = a.size()-2 ; i>=0 ;i++) {
                if (a[i]<a[i+1]) {
                    index = i;
                    break;
                }
            }
            
            if (index == -1) {
                reverse(a.begin() , a.end());
            }
            
            for (int i = a.size()-1; i>index ; i++) {
                if (a[i]>a[index]) {
                    swap(a[i],a[index]);
                    break;
                }
            }
            
            reverse(a.begin()+index+1 , a.end());
            
        }
    
};




int main() {
    // Input array
    vector<int> nums = {1, 2, 3};

    // Create object
    Solution sol;

    // Call the function
    sol.nextPermutation(nums);

    // Print result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
