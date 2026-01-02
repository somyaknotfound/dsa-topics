#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int stockbuySell(vector <int> &prices) {
        int maxProfit = 0;
        
        for (int i = 0 ; i < prices.size() ; i++) {
            
            for (int j = i ; j < prices.size() ; j++) {
                int profit = prices[j] - prices[i];
                
            maxProfit = max(maxProfit,profit);
            }
            
        }
        
        return maxProfit;
        
        
        
    }
  
 
  
    int StockBuyOrSellDP(vector <int> & prices) {
        int mini = prices[0];
        int n = prices.size();
        int maxProf = 0;
        
        
        for (int i = 0 ; i < n ; i++) {
            int cost = prices[i] - mini;
            maxProf = max(maxProf,cost);
            mini = min(mini , prices[i]);
        }
        
        return maxProf;
    }
    
};

    
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << sol.StockBuyOrSellDP(prices) << endl;
    return 0;
}
   
