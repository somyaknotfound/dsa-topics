class Solution{
    private:
        int mcm(vector <int> &nums , int i , int j , vector <vector<int>>&dp) {
            if (i>=j) {
                return 0;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int ans = INT_MAX;

            for (int k = i ; k <= j-1 ; k++) {
                int temp = mcm(nums,i,k,dp) + mcm(nums,k+1,j,dp) + nums[i-1]*nums[k] * nums[j];

                ans = min(ans , temp);

            }

            return dp[i][j] =  ans;
        }

	public:
		int matrixMultiplication(vector<int>& nums){
            //your code goes here
            int n = nums.size();

            vector <vector <int>> dp (n , vector<int>(n , -1));
            return mcm(nums,1,nums.size()-1 , dp);

    	}
};
