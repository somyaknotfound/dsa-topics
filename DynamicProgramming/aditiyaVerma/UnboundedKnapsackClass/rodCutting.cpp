class Solution {
  public:
    int cutRod(vector<int> &price) {
        
        int n = price.size();
        // code here
        vector <int> len(n);
        
        
        
        for (int i = 0  ;  i < n ; i++) {
            len[i] = i+1;
        }
        
        int P = len[n-1];
        
        int dp[n+1][P+1];
        
        for (int i = 0 ; i < n +1 ; i++) {
            for (int j = 0 ; j < P +1 ; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        
        for (int i = 1 ; i < n+1 ; i++) {
            for (int j = 1 ; j < P + 1 ; j++) {
                if (len[i-1]<=j) {
                    dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]] , dp[i-1][j]);
                    
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][P];
    }
};
