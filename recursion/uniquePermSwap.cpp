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
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    
    solve(ip , op1);
    solve(ip , op2);
    
}


void PermCapital(string ip , string op) {
    if (ip.length() == 0) {
        cout << op << endl;
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    op1.push_back(ip[0]);
    op2.push_back((char)toupper(ip[0]));
    ip.erase(ip.begin());
    
    PermCapital(ip , op1);
    PermCapital(ip , op2);
    
}


void genAllPermute(string &ip , int idx ,vector<string> &op) {
    if (idx == ip.size()) {
        op.push_back(ip);
        return;
    }
    
    unordered_set<char> used;
    
    
    for (int i = idx ; i < ip.size() ; i++) {
        if (used.count(ip[i])) {
            continue;
        }
        used.insert(ip[i]);
        
        swap(ip[i], ip[idx]);
        genAllPermute(ip, idx + 1, op);
        swap(ip[i], ip[idx]);
        }
    }








int main() { 
    string ip;
    cin >>ip;
    
    sort(ip.begin() , ip.end());
    
   
    
    int idx = 0;
    vector <string> ans;
    
    genAllPermute(ip,0,ans);
    
    
    for (string s : ans) {
        cout << s << endl;
    }
    
    
    // op.push_back(ip[0]);
    // ip.erase(ip.begin() +0);
    
    // solve(ip , op);
    // PermCapital(ip,op);
}
