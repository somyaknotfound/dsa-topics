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


int main() {
    
    string X;
    string Y;
    cin >> X >> Y;
    memset(t,-1,sizeof(t));
    cout << "count of longestSubseq:";
    cout << LCS(X,Y,X.length() , Y.length()) << endl; 
    
    cout << "Count of longest substring:";
    cout <<longestcommonSubstring(X,Y,X.length() , Y.length()) << endl;
    
    return 0;
}
