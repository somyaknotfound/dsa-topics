/*
==============================================================
LEETCODE 410 : SPLIT ARRAY LARGEST SUM
==============================================================

PROBLEM:
--------
Given:

nums = integer array
k    = number of subarrays

Split nums into exactly k NON-EMPTY contiguous subarrays
such that the largest subarray sum is minimized.

Return that minimized largest sum.

--------------------------------------------------------------
EXAMPLE:
--------------------------------------------------------------

nums = [7,2,5,10,8]
k = 2

Possible splits:

1)
[7] | [2,5,10,8]
Largest sum = 25

2)
[7,2] | [5,10,8]
Largest sum = 23

3)
[7,2,5] | [10,8]
Largest sum = 18

4)
[7,2,5,10] | [8]
Largest sum = 24

Minimum possible largest sum = 18

Answer = 18

==============================================================
INTUITION
==============================================================

We are minimizing the MAXIMUM subarray sum.

This screams:
BINARY SEARCH ON ANSWER.

We guess a value:

mid = maximum allowed sum per subarray

Question:

"Can I split the array into <= k subarrays
 such that each subarray sum is <= mid ?"

If yes -> maybe smaller answer exists.
If no  -> need bigger mid.

==============================================================
SEARCH SPACE
==============================================================

LOW:
----
Smallest possible answer =
largest element in array

Why?

No subarray can avoid containing that element.

So:

low = max(nums)

--------------------------------------------------------------

HIGH:
-----
Largest possible answer =
sum of whole array

Why?

If no split happens, whole array = one subarray.

So:

high = total sum(nums)

==============================================================
CHECK FUNCTION
==============================================================

check(nums, limit)

Meaning:

"If max allowed subarray sum = limit,
 how many subarrays do I need?"

We greedily keep adding numbers.

If adding current number exceeds limit:

Start a NEW subarray.

That guarantees minimum subarrays for that limit.

--------------------------------------------------------------
EXAMPLE
--------------------------------------------------------------

nums = [7,2,5,10,8]
limit = 18

Start:

sum = 0
parts = 1

Take 7:
sum = 7

Take 2:
sum = 9

Take 5:
sum = 14

Take 10:
14 + 10 = 24 > 18

Need new subarray

parts = 2
sum = 10

Take 8:
10 + 8 = 18

Done.

Subarrays needed = 2

Since 2 <= k
This limit works.

==============================================================
BINARY SEARCH CONDITION
==============================================================

If:

check(nums, mid) <= k

mid is VALID.

Try smaller answer:

high = mid - 1

--------------------------------------------------------------

Else:

mid too small.

Need larger allowed sum.

low = mid + 1

==============================================================
TIME COMPLEXITY
==============================================================

check() = O(n)

Binary search range:
max(nums) -> sum(nums)

Total:

O(n * log(sum(nums)))

Space:
O(1)

==============================================================
CODE
==============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    Returns number of subarrays needed
    if max allowed subarray sum = limit
    */
    int check(vector<int>& nums, int limit) {

        int parts = 1;
        int currentSum = 0;

        for (int num : nums) {

            /*
            If adding current number
            exceeds allowed limit,
            start a new subarray.
            */
            if (currentSum + num > limit) {
                parts++;
                currentSum = num;
            }
            else {
                currentSum += num;
            }
        }

        return parts;
    }


    int splitArray(vector<int>& nums, int k) {

        // Minimum possible answer
        int low =
        *max_element(nums.begin(), nums.end());

        // Maximum possible answer
        int high =
        accumulate(nums.begin(), nums.end(), 0);

        int ans = high;

        while (low <= high) {

            int mid =
            low + (high - low) / 2;

            /*
            If we can split into <= k parts,
            mid works.
            */
            if (check(nums, mid) <= k) {
                ans = mid;
                high = mid - 1;
            }

            /*
            Too many subarrays needed.
            mid too small.
            */
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


/*
==============================================================
MAIN FUNCTION TEST
==============================================================

nums = [7,2,5,10,8]
k = 2

Expected output:
18

Split:

[7,2,5] = 14
[10,8]  = 18

Largest = 18
(minimum possible)

==============================================================
*/

int main() {

    vector<int> nums = {7,2,5,10,8};
    int k = 2;

    Solution sol;

    int ans = sol.splitArray(nums, k);

    cout << ans << endl;   // 18

    return 0;
}
