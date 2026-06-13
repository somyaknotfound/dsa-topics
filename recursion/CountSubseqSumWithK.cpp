class Solution{
    public: 
    void CountSubseq(vector <int>&ds , vector <int> &nums , int n , int ind , int varsum , int k, int &count) {
        if (ind == nums.size()) {
            if (varsum == k) {
                count++;
            }
            return;
        }

        ds.push_back(nums[ind]);
        varsum+=nums[ind];
        CountSubseq(ds,nums,n,ind+1,varsum,k ,count);

        ds.pop_back();
        varsum-=nums[ind];


        CountSubseq(ds,nums,n,ind+1,varsum,k ,count);


    }


    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here

        vector <int> ds;
        int count = 0;

        CountSubseq(ds , nums , nums.size() , 0, 0 , k , count);


        return count;

    }
};
