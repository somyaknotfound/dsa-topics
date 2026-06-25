class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int diff = target;

        int sum = accumulate(nums.begin(), nums.end() , 0);

        
        // check abs
        if (abs(diff) > sum) return 0;

        if ((diff+sum)%2 != 0) return 0;

        int s = (diff+sum)/2;

        int dp[n+1][s+1];

        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;

        for (int i = 1; i < n+1 ; i++) {
            for (int j = 0 ; j < s + 1; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }


        return dp[n][s];
    }
};
