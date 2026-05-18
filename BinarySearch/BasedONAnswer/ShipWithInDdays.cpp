#include<bits/stdc++.h>
using namespace std;


class Solution {
    public: 
        int function(vector <int> & weights , int capacity) {
            int day = 1;
            int load = 0;
            
            for (int w : weights) {
                if (load + w > capacity) {
                    day++;
                    load = w;
                } else {
                    load+=w;
                }
            }
            
            return day;
            
            
        }
    
    
        int shipDays(vector<int> &weights , int days) {
            int left = *max_element(weights.begin() ,weights.end());
            int right = accumulate(weights.begin() , weights.end() , 0);
            
            
            for (int day = left ; day<=right ; day++) {
                int needed = function(weights , day);
                
                
                if (needed <= days) {
                    return day;
                }
                
            }
            
            return right;
        }
        
        int shipDaysOptimal(vector<int> &weights , int days) {
            int left = *max_element(weights.begin() ,weights.end());
            int right = accumulate(weights.begin() , weights.end() , 0);
            int ans = -1;
            
            while (left <= right) {
                int mid = (left + right) /2 ;
                
                int needed = function(weights , mid);
                
                
                if (needed<=days) {
                    ans = mid;
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
            
            return ans;
             
            
        }
        
};


int main() {
    // Input weights
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    // Days to ship
    int d = 5;
    // Create Solution instance
    Solution sol;
    // Call the function and print result
    cout << sol.shipDaysOptimal(weights, d) << "\n";
    return 0;
}
