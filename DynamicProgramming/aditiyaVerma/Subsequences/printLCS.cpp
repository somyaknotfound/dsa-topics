#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int LCS(string X, string Y , int n , int m) {
    if (n == 0 || m == 0) {
        return 0;
    }
    
    
    if (t[n][m] != -1) {
        return t[n][m];
    }
    
    
    
    
    if(X[n-1] == Y[m-1]) {
        return t[n][m] = 1 + LCS(X,Y , n-1 , m-1);
    } else {
        return t[n][m] =  max(LCS(X,Y,n-1,m) , LCS(X,Y,n,m-1));
    }
}



int longestcommonSubstring(string X , string Y, int n , int m) {
    int dp[n+1][m+1];
    
    for (int i = 0 ; i < n+1 ; i++) {
        for (int j = 0 ; j< m+1 ; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    
    for (int i = 1 ; i < n+1 ; i++) {
        for (int j = 1 ; j< m+1 ; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(dp[i][j] , ans);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    return  ans;
}


string printLCS(string s1 , string s2) {
    int n = s1.size();
    int m = s2.size();
    
    
    int dp[n+1][m+1];
    
    for (int i = 0 ; i < n+1 ; i++) {
        for (int j = 0 ; j < m+1 ; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < n+1 ; i++) {
        for (int j = 1 ; j< m+1 ; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    int i = m;
    int j = n;
    
    string s = "";
    
    while (i>0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            s.push_back(s1[i-1]);
            i--;
            j--;
        } else {
            if (dp[i-1][j] > dp[i][j-1]) {
                j--; 
            } else {
                i--;
            }
        }
    }
    
    reverse(s.begin() , s.end());
    
    return s;
}


int main() {
    
    string X;
    string Y;
    cin >> X >> Y;
    memset(t,-1,sizeof(t));
    cout << "count of longestSubseq:";
    cout << LCS(X,Y,X.length() , Y.length()) << endl; 
    cout << "printLCS: ";
    cout << printLCS(X,Y) << endl;
    
    cout << "Count of longest substring:";
    cout <<longestcommonSubstring(X,Y,X.length() , Y.length()) << endl;
    
    return 0;
}
