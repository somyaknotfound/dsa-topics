#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> leaders(vector <int> &a) {
            vector <int> ans;
            
            
            for (int i = 0 ;  i < a.size() ; i++) {
                bool leader = true; 
                
                for (int j = i+1; j < a.size() ; j++) {
                    if (a[j]>= a[i] ) {
                        leader = false;
                        break;
                    }
                }
                
                if (leader) {
                    ans.push_back(a[i]);
                }
            }
            
            return ans;
        }
        
        
        vector <int> Optimalapp(vector <int> &a) {
            vector <int> ans;
            
            if (a.empty()) {
                return ans;
            }
            
            int max = a[a.size()-1];
            ans.push_back(max);
            
            
            
            for (int i = a.size()-2 ; i>=0 ; i--) {
                if (a[i] > max) {
                    ans.push_back(a[i]);
                    max = a[i];
                }
            }
            
            reverse(ans.begin() , ans.end());
            
            
            return ans;
        }
        
        
    
};




int main() {
    // Input array
    vector<int> nums = {1, 2, 5, 3, 1, 2};
    
    Solution sol;
    
    vector <int> ans = sol.Optimalapp(nums);
    
    for (int num : ans) {
        cout << num << " ";
    }
   
    return 0;
}
