// leetcode 779 0 -> 01 ; 1-> 10 find for a particular n and k
// observations search for shorter problem for n-1 and k lies between mid or beyond that if it does behind mid just return smaller function else complement with k-mid pos



class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k ==1 ) {
            return 0;
        }

        int mid = (pow(2,n-1)) /2 ;

        if (k <= mid) {
            return kthGrammar(n-1,k);
        } else {
            return !kthGrammar(n-1,k-mid);
        }
    }
};
