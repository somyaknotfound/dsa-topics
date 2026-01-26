#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int LongestSubarraywSum0(vector <int> &arr) {
    int maxLen = 0;
    
    unordered_map <int,int> sumIndexMap;
    
    int sum = 0 ;
    for (int i ; i < (int) arr.size()  ; i++) {
        sum+=arr[i];
        
        if (sum == 0) {
            maxLen = i+1;
        }
        
        else if (sumIndexMap.find(sum)!= sumIndexMap.end()) {
            maxLen = max(maxLen , i  - sumIndexMap[sum]);
        }
        
        else {
            sumIndexMap[sum] = i;
        }
    }
    
    return maxLen;
    
    }
    
};


int main() {
    Solution sol;
    
    vector<int> a = {9, -3, 3, -1, 6, -5};
    // print result
    
    cout << sol.LongestSubarraywSum0(a) << endl;
    // exit
    return 0;
    
    
}
