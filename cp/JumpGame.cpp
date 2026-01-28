class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        int jumps = 0;
        int current_end = 0;

        for (int i = 0 ; i < n-1 ; i++) {
            farthest = max(farthest , i + nums[i]);
            
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            if (current_end >= n-1) {
                break;
            }
            }

        }
        return jumps;



        
    }


 
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0 ; i < n ; i++) {
            if (i> farthest) return false;
            farthest = max(farthest , i + nums[i]);
            if (farthest >= n-1) {
                return true;
            }
        }
        return farthest>=1;
    }

};
