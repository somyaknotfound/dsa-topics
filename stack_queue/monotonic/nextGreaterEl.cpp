class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack <int> st;
        vector <int> ans(n);


        for (int i = 2*n - 1; i >=0 ; i--) {
            int ind = i%n;
            int curEl = nums[ind];

            if (!st.empty() && st.top() <= curEl) {
                st.pop();
            }

            if (i < n) {
                if (st.empty()) {
                    ans[i] = -1;
                } else {
                    ans[i] = st.top();
                }
            }

            st.push(curEl);

        }

        return ans;
    }
};




class Solution {
  public:
    vector<int> nextLargerElementOpt(vector<int>& arr) {
        // code here
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n);
        
        for (int i = n-1 ; i>= 0 ; i--) {
            int curEl = arr[i];
            
            while (!st.empty() && st.top() <= curEl) {
                st.pop();
            }
            
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
                
                
                
            }
            
            st.push(curEl);
        }
        
        return ans;
        
    }
};
