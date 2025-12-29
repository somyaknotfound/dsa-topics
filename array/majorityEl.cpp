#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int majorityElement(vector <int> &arr) {
            for (int i = 0 ; i < arr.size();i++) {
                int cnt = 0;
                for (int j = 0 ; j < arr.size();j++) {
                    if (arr[j]==arr[i]) {
                        cnt++;
                    }
                }
                if (cnt > arr.size()/2) {
                    return arr[i];
                }
            }
            return -1;
        }
        
        
        int majorityElementMap(vector <int> &arr) {
            unordered_map<int,int> mpp;
            
            for (int i = 0 ; i < arr.size() ;i++) {
                mpp[arr[i]]++;
                
            }
            
            for (auto &it : mpp) {
                if (it.second > arr.size()/2) {
                    return it.first;
                }
            }
            
            return -1;
        }
        
        int MooreVotingAlgo(vector <int> &nums) {
            int n = nums.size();
            int el;
            
            int cnt= 0;
            for (int i = 0  ; i < n ; i++ ){
                if (cnt == 0) {
                    el = nums[i];
                    cnt = 1;
                } else if (nums[i]==el) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
            return el;
        }
        
    
    
};


int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    
    // Create an instance of Solution class
    Solution sol;
 
    int ans = sol.MooreVotingAlgo(arr);
    
    // Print the majority element found
    cout << "The majority element is: " << ans << endl;
    
    return 0;
}
