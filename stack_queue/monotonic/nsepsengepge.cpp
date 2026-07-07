
// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> findNGE(vector<int>& arr) {
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n);
        
        for (int i = n-1 ; i>=0 ; i--) {
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

    vector<int> findNSE(vector<int>& arr) {
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n);
        
        for (int i = n-1 ; i>=0 ; i--) {
            int curEl = arr[i];
            
            while (!st.empty() && st.top() >= curEl) {
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

    vector<int> findPGE(vector<int>& arr) {
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n);
        
        for (int i = 0 ; i < n ; i++) {
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

    vector<int> findPSE(vector<int>& arr) {
        stack <int> st;
        int n = arr.size();
        vector <int> ans(n);
        
        for (int i = 0 ; i < n ; i++) {
            int curEl = arr[i];
            
            while (!st.empty() && st.top() >= curEl) {
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
    
    stack<int> st;
// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps
// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps
// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps
// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps
// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

// Push
st.push(i);

// Compare
arr[st.top()] >= arr[i]

// Answer
ans[i] = st.empty() ? -1 : st.top();
// helps

public:
    void solve(vector<int>& arr) {

        vector<int> nge = findNGE(arr);
        vector<int> nse = findNSE(arr);
        vector<int> pge = findPGE(arr);
        vector<int> pse = findPSE(arr);

        cout << "Next Greater: ";
        for (int x : nge) cout << x << " ";
        cout << "\n";

        cout << "Next Smaller: ";
        for (int x : nse) cout << x << " ";
        cout << "\n";

        cout << "Previous Greater: ";
        for (int x : pge) cout << x << " ";
        cout << "\n";

        cout << "Previous Smaller: ";
        for (int x : pse) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    Solution obj;
    obj.solve(arr);

    return 0;
}
