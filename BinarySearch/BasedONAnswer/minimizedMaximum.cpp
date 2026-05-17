/*
=========================================================
LEETCODE 2064 : Minimized Maximum of Products per Store
=========================================================

PROBLEM:
--------
We are given:

n = number of stores
quantities[i] = number of products of type i

Rules:
1. Each store can contain ONLY one product type.
2. A product type can be split across multiple stores.

Goal:
-----
Minimize the maximum number of products assigned
to any single store.

---------------------------------------------------------
EXAMPLE:
---------------------------------------------------------

n = 6
quantities = {11, 6}

Suppose we guess:

d = 4

Question:
Can every store have at most 4 products?

Type 1: 11 products

Distribution:
4 + 4 + 3

Stores needed = 3

Type 2: 6 products

Distribution:
4 + 2

Stores needed = 2

Total stores needed:

3 + 2 = 5

Since:

5 <= 6

This distribution is possible.

---------------------------------------------------------
KEY OBSERVATION:
---------------------------------------------------------

If d increases:

stores needed decreases

If d decreases:

stores needed increases

This is MONOTONIC.

So we can binary search on answer.

Search space:

minimum answer = 1
maximum answer = max(quantities)

---------------------------------------------------------
CHECK FUNCTION:
---------------------------------------------------------

check(quantities, d)

Meaning:

"If every store can hold at most d products,
how many stores would we need?"

Formula:

stores needed for one product type:

ceil(items / d)

Integer trick:

(items + d - 1) / d

Examples:

11 items, d = 4

(11 + 4 - 1)/4
= 14/4
= 3

Meaning 3 stores needed.

---------------------------------------------------------
BINARY SEARCH LOGIC:
---------------------------------------------------------

If:

check(mid) <= n

mid is possible.

Maybe smaller answer exists.

Move left:

high = mid - 1

Else:

mid too small.

Need larger capacity.

Move right:

low = mid + 1

---------------------------------------------------------
TIME COMPLEXITY:
---------------------------------------------------------

check() = O(k)

k = number of product types

Binary search = O(log(maxElement))

Total:

O(k * log(maxElement))

=========================================================
CODE
=========================================================
*/

class Solution {
public:

    // Returns stores needed if each store
    // can hold at most d products.
    int check(vector<int>& quantities, int d) {

        int sum = 0;

        for(int items : quantities) {

            // ceil(items / d)
            sum += (items + d - 1) / d;
        }

        return sum;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;

        int high =
        *max_element(
            quantities.begin(),
            quantities.end()
        );

        int ans = -1;


        while(low <= high) {

            int mid =
            low + (high - low)/2;


            // mid works
            if(check(quantities, mid) <= n) {

                ans = mid;

                // search smaller answer
                high = mid - 1;
            }

            // mid too small
            else {

                // search bigger answer
                low = mid + 1;
            }
        }

        return ans;
    }
};


/*
=========================================================
MAIN FUNCTION TEST
=========================================================

Input:

n = 6
quantities = {11, 6}

Expected answer:

3

Distribution:

11 -> 3 + 3 + 3 + 2

6 -> 3 + 3

Total stores:

4 + 2 = 6

No store has more than 3 products.

=========================================================
*/

int main() {

    Solution obj;

    int n = 6;

    vector<int> quantities = {11, 6};


    cout << obj.minimizedMaximum(
        n,
        quantities
    );

    return 0;
}
