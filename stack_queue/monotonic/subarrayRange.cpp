class Solution {

private:

vector <int> findNGE(vector <int> &v) {
    int n = v.size();
    stack <int> st;
    vector <int> ans(n);

    for (int i = n -1 ; i >= 0 ; i--) {
        int curEl = v[i];

        while (!st.empty() && v[st.top()] <= curEl ) {
            st.pop();
        }

        ans[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return ans;
}
vector <int> findPSEE(vector <int> &v) {
    int n = v.size();
    stack <int> st;
    vector <int> ans(n);

    for (int i = 0 ; i < n ; i++) {
        int curEl = v[i];

        while (!st.empty() && v[st.top()] > curEl ) {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    return ans;
}
vector <int> findNSE(vector <int> &v) {
    int n = v.size();
    stack <int> st;
    vector <int> ans(n);

    for (int i = n -1 ; i >= 0 ; i--) {
        int curEl = v[i];

        while (!st.empty() && v[st.top()] >= curEl ) {
            st.pop();
        }

        ans[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return ans;
}
vector <int> findPGEE(vector <int> &v) {
    int n = v.size();
    stack <int> st;
    vector <int> ans(n);

    for (int i = 0 ; i < n ; i++) {
        int curEl = v[i];

        while (!st.empty() && v[st.top()] < curEl ) {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    return ans;
}

    


long long subMax(vector <int> &v) {
    int n =v.size();
    vector <int> nge = findNGE(v);
    vector <int> pgee = findPGEE(v);
    long long sum = 0;

    for (int i = 0 ; i < n ; i++) {
        int left = i - pgee[i];
        int right = nge[i] - i;

        long long freq = 1LL * left * right;
        long long val = freq * v[i];
        sum += val;
    }

    return sum;
}

long long subMin(vector <int> &v) {
    int n =v.size();
    vector <int> nse = findNSE(v);
    vector<int> psee = findPSEE(v);
    long long sum = 0;

    for (int i = 0 ; i < n ; i++) {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = 1LL * left * right;
        long long val = freq * v[i];
        sum += val;
    }

    return sum;
}


public:
    long long subArrayRanges(vector<int>& nums) {
        return (subMax(nums) - subMin(nums));
    }
};





Here's a concise checklist of the mistakes you made while implementing Sum of Subarray Ranges:

Monotonic Stack Checklist
1. Values vs Indices ❌
Wrong: st.push(curEl);
Correct: st.push(i);
If the stack stores indices, always compare with arr[st.top()].
2. Traversal Direction ❌
Next → Traverse right → left
Previous → Traverse left → right
3. Sentinel Values ❌
Next (NGE/NSE): use n if none exists.
Previous (PGE/PSE): use -1 if none exists.

Reason:

left = i - prev[i];
right = next[i] - i;

These formulas work uniformly only with -1 and n.

4. Duplicate Handling ❌

One side must be strict, the other non-strict.

For Minimums:

PSE : >
NSE : >=

For Maximums:

PGE : <
NGE : <=

(Or the opposite convention: >=/> and <=/<.)

5. if vs while ❌

Always restore the monotonic property completely.

while (!st.empty() && ...)
    st.pop();

Never use if here.

6. Integer Overflow ❌

Use long long before multiplication.

long long freq = 1LL * left * right;
7. Return Type ❌

If you're accumulating into a long long, return a long long, not an int.

Final Template to Memorize
Function	Traverse	Pop While	Sentinel
NGE	Right → Left	<=	n
NSE	Right → Left	>=	n
PGE	Left → Right	<	-1
PSE	Left → Right	>	-1

This table plus the rule "store indices, not values" is enough to derive almost every monotonic stack contribution problem (Largest Rectangle, Sum of Subarray Minimums, Sum of Subarray Ranges, etc.).
