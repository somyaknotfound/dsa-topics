#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool linearSearch(vector<int> &a, int num) {
            int n = a.size();
            
            for (int i =  0  ; i < n ; i++) {
                if (a[i]==num) {
                    return true;
                }
            }
            return false;
        }
    
    
    
    public:
    
        int longestConsecutive(vector<int> &a) {
            if (a.size()==0) {
                return 0;
            }
            
            int longest =  1;
            int n = a.size();
            
            
            for (int i = 0 ; i < n ; i++) {
                int x = a[i];
                
                int cnt = 1;
                
                while(linearSearch(a,x+1)) {
                    x+=1;
                    cnt+=1;
                }
                
                longest = max(cnt,longest);
            }
            return longest;
        }
        
        int betterSoln(vector <int> &a) {
            
            int longest = 1;
            
            int n = a.size();
            if (n==0) return 0;
            
            int cnt = 0;
            
            int lastSmaller = INT_MIN;
            sort(a.begin() , a.end());
            for (int i = 0 ; i < n ; i++) {
                
                if (a[i]-1 == lastSmaller) {
                    cnt++;
                    lastSmaller = a[i];
                }
                
                else if(lastSmaller != a[i]) {
                   cnt = 1;
                   lastSmaller = a[i];
                }
                
                longest = max(longest , cnt);
                
                
            }
            
            return longest;
            
        }
        
        
        int longestConsOptimal(vector <int> &a) {
            int n = a.size();
            int longest = 1 ;
            
            unordered_set <int> st;
            
            for (int i = 0 ; i < n ; i++) {
                st.insert(a[i]);
            }
            
            for (auto &it : st) {
                if (st.find(it-1)==st.end()) {
                    int cnt = 1;
                    int x = it;
                    
                    while (st.find(x+1)!=st.end()) {
                        x = x+1;
                        cnt++;
                    }
                    
                    longest = max(cnt,longest);
                }
            }
            return longest;
        }
        
    
        
        
        
    
};




int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2};

    // Create an instance of the Solution class
    Solution solution;

    // Function call for longest consecutive sequence
    int ans = solution.longestConsOptimal(a);
    cout << "The longest consecutive sequence is " << ans << "\n"; 
    return 0;
}
