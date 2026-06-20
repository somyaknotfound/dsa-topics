class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0;
        int rightsum;
        int totalSum = accumulate(nums.begin() , nums.end() , 0);

        for (int i = 0 ; i < nums.size() ; i++) {
            rightsum = totalSum - leftsum - nums[i];

            if (rightsum == leftsum) {
                return i;
            }

            leftsum+=nums[i];
        }

        return -1;
    }
};
