#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int LongestSubarraySumWithKpos(vector <int> a ,int k) {
            int Maxlen = 0;
            
            unordered_map <long long,int> pfs;
            
            long long sum = 0;
            for (int i= 0; i < a.size();i++) {
                sum+=a[i];
                if (sum==k) {
                    Maxlen = max(Maxlen,i+1);
                }
                
                int rem = sum - k;
                
                if (pfs.find(rem) != pfs.end()) {
                    int len = i - pfs[rem];
                    Maxlen = max(Maxlen,len);
                }
                pfs[sum] = i;
            }
            
            return Maxlen;
        }
        
        int SlidingWindowsApproach(vector <int> a , int k) {
            int n = a.size();
            int Maxlen = 0;
            int left = 0 ; int right = 0;
            
            int sum = a[0];
            
            while (right < n) {
                if (left<=right && sum > k) {
                    sum-= a[left];
                    left++;
                }
                
                if (sum == k) {
                    Maxlen = max(Maxlen,right-left+1);
                } right++;
                
                if (right<n) {
                    sum+=a[right];
                }
            }
            
            return Maxlen;
        }
};


int main() {
    Solution sol;
    vector <int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k = sol.SlidingWindowsApproach(arr,3);
    cout << k << " ";
    
    
    
    
    
    return 0;
}














