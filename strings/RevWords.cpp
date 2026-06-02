#include <bits/stdc++.h>
using namespace std;


void namerev(char name[] , int n) {
    int s = 0;
    int e = n-1;
    
    
    while (s < e) {
        swap(name[s++] , name[e--]);
    }
    
    
}


string RevString(string s) {
    vector <string> words;
    string temp = "";
    
    for (char ch : s) {
        if (ch != ' ') {
            temp+=ch;
        }
        else {
            if (temp!="") {
                words.push_back(temp);
                temp = "";
            }
        }
    }
    
    if (temp!="") {
        words.push_back(temp);
    }
    
    string ans;
    
    for (int i = words.size() - 1 ; i>=0 ; i--) {
        ans+=words[i];
        
        if (i!=0) {
            ans+=" ";
        }
    }
    
    return ans;
    
    
    
}

string BetterRev(string s){
    reverse(s.begin() , s.end());
    int start = 0;
    for (int end = 0 ; end <= s.size() ; end++) {
        if (end == s.size() || s[end] == ' ') {
            reverse(s.begin() + start , s.begin() + end);
            start = end+1;
        }
    }
    
    return s;
}

string OptimalRev(string s) {
    string ans;
    int i = s.size() - 1;
    
    
    while (i>= 0) {
        while (i>=0 && s[i] == ' ') i--;
        if (i < 0) break;
        
        int j = i;
        
        while (i>= 0 && s[i] != ' ') i--;
        
        if (!ans.empty()) ans+=' ';
        ans += s.substr(i+1 , j-i);
    }
    
    return ans;
}


int main() {
    
    
    
    string s;
    getline(cin , s);
    string rev = OptimalRev(s);
    cout << rev ;
    
    
   
    
    
    
    return 0 ;
    
}
