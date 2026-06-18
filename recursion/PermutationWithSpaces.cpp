#include <bits/stdc++.h>
using namespace std;


void solve(string ip , string op) {
    if (ip.length() == 0) {
        cout << op <<endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    
    op1.push_back(' ');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    
    solve(ip , op1);
    solve(ip , op2);
    
}


class Solution {
  public:
  
  
    void Perm(string sip , string sop , vector <string> &ans) {
        if (sip.length() == 0) {
            ans.push_back(sop);
            return;
        }
        
        string op1 = sop;
        string op2 = sop;
        
        op1.push_back(' ');
        op1.push_back(sip[0]);
        op2.push_back(sip[0]);
        sip.erase(sip.begin() + 0);
        
        Perm(sip , op1 , ans);
        Perm(sip , op2 , ans);
        
        
    }

    vector<string> permutation(string s) {
        // Code Here
        string sip = s;
        string sop = "";
        sop.push_back(sip[0]);
        sip.erase(sip.begin() +0);
        
        vector <string> ans;
        
        Perm(sip,sop,ans);
        
        return ans;
        
    }
};



int main() {
    string ip;
    cin >>ip;
    
    string op = "";
    
    op.push_back(ip[0]);
    ip.erase(ip.begin() +0);
    
    solve(ip , op);
}
