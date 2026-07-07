class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n);
        
        for (int i = 0 ; i < n ; i++) {
            int curEl = arr[i];
            //store
            while (!st.empty() && curEl <= st.top()) {
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
