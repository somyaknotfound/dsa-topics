/*
==============================================================
AGGRESSIVE COWS
(Binary Search on Answer + Greedy Feasibility Check)
==============================================================

PROBLEM:
--------
Given:

nums = stall positions
k    = number of cows

Place k cows into stalls such that:

MINIMUM distance between any two cows
is MAXIMIZED.

Return that maximum minimum distance.

--------------------------------------------------------------
EXAMPLE:
--------------------------------------------------------------

nums = [1,2,4,8,9]
k = 3

Possible placements:

1,4,8
Distances = 3 , 4
Minimum = 3

1,4,9
Distances = 3 , 5
Minimum = 3

1,2,8
Distances = 1 , 6
Minimum = 1

Best answer = 3

==============================================================
INTUITION
==============================================================

We are maximizing the MINIMUM distance.

Suppose we guess:

dist = minimum distance between cows

Question:

"Can I place at least k cows
 such that every pair is at least dist apart?"

If yes -> maybe larger distance works.
If no  -> distance too large.

This becomes Binary Search on Answer.

==============================================================
GREEDY FEASIBILITY CHECK
==============================================================

CanWePlace(nums, dist, cows)

Meaning:

Can I place at least 'cows'
with spacing >= dist ?

Greedy idea:

Always place next cow
at the EARLIEST possible valid stall.

Why greedy works:
-----------------
Placing early leaves maximum room
for future cows.

If later stall works,
earlier valid stall is always better.

--------------------------------------------------------------
EXAMPLE:
--------------------------------------------------------------

nums = [1,2,4,8,9]
dist = 3

Place first cow at 1

Next earliest valid:

4

Next earliest valid:

8

Placed 3 cows.

Return true.

==============================================================
BRUTE FORCE APPROACH
==============================================================

Try every possible distance:

1 -> max(nums)-min(nums)

Check each distance.

First distance that fails:
answer = previous distance.

--------------------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------------------

For each distance:
O(n)

Distance range:
(maxi - mini)

Total:
O(n * (maxi-mini))

==============================================================
OPTIMIZED APPROACH
==============================================================

Observation:

If distance 3 works:
distance 2,1 also work.

If distance 8 fails:
distance 9,10 also fail.

MONOTONIC.

Binary search valid.

--------------------------------------------------------------
SEARCH SPACE:
--------------------------------------------------------------

LOW:
1

Minimum meaningful distance.

HIGH:
max(nums)-min(nums)

Largest possible distance.

==============================================================
BINARY SEARCH RULE
==============================================================

If CanWePlace(mid) == true:

mid works.

Try bigger distance.

low = mid + 1

--------------------------------------------------------------

Else:

mid too large.

high = mid - 1

==============================================================
WHY RETURN HIGH?
==============================================================

After loop:

low  = first invalid distance
high = last valid distance

Need largest valid distance.

Return high.

==============================================================
TIME COMPLEXITY (OPTIMAL)
==============================================================

Sorting:
O(n log n)

Binary search:
O(log(maxi-mini))

Each check:
O(n)

Total:

O(n log n + n log(maxi-mini))

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
    GREEDY CHECK FUNCTION
    Can we place at least k cows
    with minimum spacing = dist ?
    */
    bool CanWePlace(vector<int>& nums,
                    int dist,
                    int cows) {

        int cowCount = 1;
        int last = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] - last >= dist) {
                cowCount++;
                last = nums[i];
            }
        }

        return cowCount >= cows;
    }


    /*
    ==========================================================
    BRUTE FORCE
    ==========================================================
    */
    int aggressiveCowsBrute(vector<int>& nums,
                            int k) {

        sort(nums.begin(), nums.end());

        int maxi =
        *max_element(nums.begin(),
                     nums.end());

        int mini =
        *min_element(nums.begin(),
                     nums.end());

        for(int dist = 1;
            dist <= maxi - mini;
            dist++) {

            if(!CanWePlace(nums, dist, k)) {
                return dist - 1;
            }
        }

        return maxi - mini;
    }



    /*
    ==========================================================
    OPTIMIZED (BINARY SEARCH)
    ==========================================================
    */
    int aggressiveCows(vector<int>& nums,
                       int k) {

        sort(nums.begin(), nums.end());

        int maxi =
        *max_element(nums.begin(),
                     nums.end());

        int mini =
        *min_element(nums.begin(),
                     nums.end());

        int low = 1;
        int high = maxi - mini;

        while(low <= high) {

            int mid =
            low + (high - low)/2;

            if(CanWePlace(nums, mid, k)) {

                // valid
                // try bigger distance
                low = mid + 1;
            }
            else {

                // too large
                high = mid - 1;
            }
        }

        return high;
    }
};


/*
==============================================================
MAIN FUNCTION TEST
==============================================================

Input:
nums = [1,2,4,8,9]
k = 3

Possible optimal placement:
1,4,8

Distances:
3 , 4

Minimum = 3

Expected Output:
3

==============================================================
*/

int main() {

    vector<int> nums = {1,2,4,8,9};
    int k = 3;

    Solution sol;

    cout << "Brute Force : "
         << sol.aggressiveCowsBrute(nums, k)
         << endl;

    cout << "Optimized   : "
         << sol.aggressiveCows(nums, k)
         << endl;

    return 0;
}
