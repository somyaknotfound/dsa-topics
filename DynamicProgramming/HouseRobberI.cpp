/*
HOUSE ROBBER (DP)

Problem:
You are given an array nums where nums[i] is money in house i.
Cannot rob 2 adjacent houses.
Return maximum money that can be robbed.

--------------------------------------------------

STATE:
dp[i] = maximum money we can rob from houses [0...i]

CHOICES at house i:

1) Skip current house:
   profit = dp[i-1]

2) Rob current house:
   profit = nums[i] + dp[i-2]

TRANSITION:

dp[i] = max(dp[i-1], dp[i-2] + nums[i])

BASE CASES:

dp[0] = nums[0]

dp[1] = max(nums[0], nums[1])

FINAL ANSWER:

dp[n-1]

--------------------------------------------------

Example:

nums = [2,7,9,3,1]

dp[0] = 2
dp[1] = 7

dp[2] = max(7, 2+9) = 11
dp[3] = max(11, 7+3) = 11
dp[4] = max(11, 11+1) = 12

DP array:
[2,7,11,11,12]

Answer = 12

--------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

(Can be optimized to O(1))
*/

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }
};
  
