class Solution {
  public:
    int minDifference(vector<int>& nums) {
        // code here
        int n = nums.size();
        long long sum = accumulate(nums.begin() , nums.end() , 0);
        
        bool dp[n+1][sum+1];
        
        for (int i = 0 ; i < n+1 ; i++) {
            for (int j = 0 ; j < sum+1 ; j++) {
                if (i==0) {
                    dp[i][j] = false;
                }
                if (j == 0) {
                    dp[i][j] = true;
                }
            }
        }
            
            for (int i = 1 ; i < n+1 ; i++) {
                for (int j =1 ; j < sum+1 ; j++) {
                    if (nums[i-1]<= j) {
                        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            
            vector <long long> lastRow;
            
            for (int i = 0 ; i <= sum/2 ; i++) {
                if (dp[n][i]) {
                    lastRow.push_back(i);
                }
            }
            
            long long mn = INT_MAX;
            for (int x : lastRow) {
                mn = min(mn,sum - 2*x);
            }
            
            return mn;
        
    }
};
