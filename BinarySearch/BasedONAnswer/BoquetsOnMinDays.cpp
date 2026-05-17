#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool isPossible(vector <int> &bloomDays , int day , int m , int k) {
            int count =  0;
            int boquests = 0;
            
            for (int bloom : bloomDays) {
                if (bloom <= day) {
                    count++;
                    if (count == k) {
                        boquests++;
                        count = 0;
                        
                    }
                } else {
                    count = 0;
                }
            }
            return boquests >= m;
        }
        
        int minDaysToMakeBoquests(vector <int> &bloomDays , int m , int k) {
            long long totalFlowers = 1LL * m * k;
            
            if (totalFlowers > bloomDays.size())  return -1;
            
            
            int low = *min_element(bloomDays.begin() , bloomDays.end());
            int high = *max_element(bloomDays.begin() , bloomDays.end());
            
            
            for (int day = low ; day <=high ; day++) {
                if (isPossible(bloomDays,day,m,k)) {
                    return day;
                }
            }
            return -1;
            
        }
};




int main() {
    
    vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    
    Solution garden;
    
    int result = garden.minDaysToMakeBoquests(bloomDays,m,k);
    
    if (result == -1) {
        cout << "Not possible to make boquests" << endl;
        
    } else {
        cout << "We can make boquests on " << result << "day" << endl;
    }
    
    
    
    
    
    return 0;
    
}
