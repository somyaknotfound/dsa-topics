#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // helper
    int CountPainter(vector<int> &C , int barrier) {
        int board = 0;
        int painter = 1;
        
        for (int i = 0 ; i < C.size()  ; i++) {
            if (C[i] + board > barrier) {
                painter++;
                board = C[i];
            }
            else {
                board+=C[i];
            }
        }
        
        return painter;
    }

    // =========================
    // BRUTE FORCE
    // =========================
    int solveBruteForce(int A , int B , vector<int> &C) {
        // Write brute force logic here
        int low = *max_element(C.begin() ,C.end());
        int high  = accumulate(C.begin() , C.end() , 0);
        int ans = high;
        
        
        for (int t = low ; t <= high ; t++) {
            if (CountPainter(C,t) <=A) {
                ans = t;
                break;
            }
        }
        
        
        return ans*B;
        
        
        
    }


    // =========================
    // OPTIMAL
    // =========================
    int solveOptimal(int A , int B , vector<int> &C) {
        // Write optimized logic here
        
        int low = *max_element(C.begin() ,C.end());
        int high  = accumulate(C.begin() , C.end() , 0);
        int ans = high;
        
        
        while (low <= high) {
            int mid = (low + high)/2;
            
            
            if (CountPainter(C,mid)<=A) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
                
            }
        }
        
        
        return ans*B;

       
    }
};


int main() {
    Solution obj;

    // -------------------------
    // Input
    // -------------------------
    int A;
    cin>> A;
    int B;
    cin>>B;
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Extra inputs if needed
    // int k;
    // cin >> k;
    
    // -------------------------
    // Brute Force Call
    // -------------------------
    int bruteAns = obj.solveBruteForce(A,B,arr);
    cout << "Brute Force: " << bruteAns << endl;


    // -------------------------
    // Optimal Call
    // -------------------------
    int optimalAns = obj.solveOptimal(A,B,arr);
    cout << "Optimal: " << optimalAns << endl;


    return 0;
}
