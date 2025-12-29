#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution {
    public:
        string TwoSumExists(vector <int> &a , int target) {
            int n = a.size();
            for (int i = 0 ; i < n ; i++) {
                for (int j = i+1 ; i < n ; i++) {
                    if (a[i]+a[j]==target) {
                        return "YES";
                    }
                }
            }
            return "NO";
        }
        
        string TwoSumMap(vector <int> &a , int target) {
            unordered_map <int,int> mpp;
            for (int i = 0 ; i < a.size(); i++) {
                int complement = target-a[i];
                if(mpp.find(complement)!= mpp.end()) {
                    return "YES";
                }
                
                mpp[a[i]] = i;
            }
            
            return "NO";
        }
        
        string TwoSumGreedy(vector <int> &a , int target) {
            int left = 0;
            int right = a.size()-1;
            sort(a.begin(),a.end());
            
            while (left < right) {
                int sum = a[left] + a[right];
                if (sum==target) {
                    return "YES";
                }
                else if(sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
            
            return "NO";
        }
};


int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    
    Solution sol;
    
    cout<<sol.TwoSumExists(arr,target)<<endl;
    cout<<sol.TwoSumMap(arr,target)<<endl;
    cout<<sol.TwoSumGreedy(arr,target)<<endl;

    
    
    return 0;
}