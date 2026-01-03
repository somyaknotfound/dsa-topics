#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> RearrangeBySign(vector <int> &a ,int n) {
           vector <int> pos;
           vector <int> neg;
           
           for (int i = 0 ; i < n ; i++) {
               if (a[i]>0) {
                   pos.push_back(a[i]);
               }
               else {
                   neg.push_back(a[i]);
               }
           }
           
           for (int i = 0 ; i < n/2 ; i++) {
               a[2*i] = pos[i];
               a[2*i +1] = neg[i];
           }
           return a;
        }
    
};




int main() {
    
    Solution sol;
    
    vector <int> a = {2,-1,-3,-4,-7,5,4,2,1,-5};
    
    sol.RearrangeBySign(a , a.size());
    
    for (int num : a) {
        cout << num << " ";
    }
    
    
    
    
    
    return 0;
}
