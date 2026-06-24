#include <bits/stdc++.h>
using namespace std;

int t[102][1002];


int knapsack(int wt[] , int val[] , int W, int n) {
    if (n==0 || W == 0) {
        return 0;
    }
    
    if (t[n][W] != -1) {
        return t[n][W];
    }
    
    if (wt[n-1] <= W) {
        return t[n][W] =  max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1) , knapsack(wt,val,W,n-1));
    }
    
    else if (wt[n-1] > W) {
        return t[n][W] =  knapsack(wt,val,W,n-1);
    }
}




int main() {
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int n = 4;
    int W = 7;
    
    // memset(t,-1,sizeof(t));
    
    for (int i = 0 ; i < n+1 ; i++) {
        for (int j = 0 ; j < W+1 ; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }
    
    for (int i = 1 ;i < n+1 ;i++) {
        for (int j = 1 ; j < W+1 ; j++) {
            if (wt[i-1] <= j) {
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
            }
            
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    cout << t[n][W] << endl;
}
