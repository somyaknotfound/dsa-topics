class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int cnt = 0;
        
        map <int,int> mpp;
        
        int xr = 0;
        mpp[xr]++;
        
        for (int i = 0  ; i < arr.size() ; i++) {
            xr^=arr[i];
            int x = xr^k;
            cnt+=mpp[x];
            mpp[xr]++;
        }
        
        return cnt;
    }

int countSubarraysXOR(vector<int>& A, int B) {
        // Initialize count of valid subarrays
        int count = 0;
        // Traverse all starting points
        for (int i = 0; i < A.size(); i++) {
            // Maintain xor of current subarray
            int xorVal = 0;
            // Extend subarray till end
            for (int j = i; j < A.size(); j++) {
                // Update xor
                xorVal ^= A[j];
                // If xor equals B, increment count
                if (xorVal == B) {
                    count++;
                }
            }
        }
        return count;
    }


};
