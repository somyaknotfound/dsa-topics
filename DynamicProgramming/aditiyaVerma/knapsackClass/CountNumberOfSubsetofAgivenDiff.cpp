#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   int countPartitions(int n, int diff, vector<int>& arr) {
        int target = accumulate(arr.begin() , arr.end() , 0);

        if (diff > target) return 0;
        if ((diff+target)%2 != 0) return 0;

        int sum = (diff + target) / 2;

        int dp[n+1][sum+1];

        // for (int i = 0 ; i < n+1 ; i++) {
        //     for (int j = 0 ; j < sum+1 ; j++) {
        //         if (i == 0) {
        //             dp[i][j] = 0;
        //         }

        //         if (j==0) {
        //             dp[i][j] = 1;
        //         }
        //     }
        // }

        // if set contains 0 and iterate for j = 0 while building
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;   

        int MOD = 1000000007;

        for (int i = 1 ; i < n+1 ; i++) {
            for (int j = 0 ; j < sum + 1 ; j++) {
                if (arr[i-1]<=j) {
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) %MOD;

                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
};
