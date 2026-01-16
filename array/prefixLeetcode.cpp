class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        unordered_map <int,int> modMap;

        int prefixSum = 0;

        modMap[0] = -1;

        for (int i = 0 ; i< n ; i++) {
            prefixSum += nums[i];

            int rem = prefixSum%k;

            if (modMap.find(rem) != modMap.end()) {
                if (i - modMap[rem] >=2) {
                    return true;
            }
                } else {
                    modMap[rem] = i;
                }
        }

        return false;
        
        
    }
};
