#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
    
    string longestCommonPrefix(vector <string> &a) {
        
        if (a.empty()) return "";
        
        
        sort(a.begin() , a.end());
        
        string first = a[0];
        
        string last = a[a.size() - 1];
        string ans;
        
        int minLength = min(first.size() , last.size());
        
        for (int i = 0 ; i < minLength ; i++) {
            if (first[i] != last[i]) break;
            
            ans += first[i];
        }
        
        
        
        return ans;
        
        
        
    }
};




int main() {
    
    
    vector <string> a = {"geezer" , "geez" , "geezbar"};
    Solution sol;
    string ans = sol.longestCommonPrefix(a);
    
    cout << ans;
    
    
    
    
    return 0;
}
