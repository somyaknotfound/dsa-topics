class Solution {
public:
    int minimumDeletions(string s) {
        int dp = 0;
        int bcount= 0;

        for (char c : s) {
            if (c == 'b') {
                bcount++;
            } else {
                dp = min(dp+1,bcount);
            }
        }
        return dp;
    }
};
