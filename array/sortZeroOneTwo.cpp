#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution {
    public:
        void sortZeroOneTwo(vector <int> & nums) {
            int czero = 0; int cone = 0 ; int ctwo = 0;
            for (int i= 0 ; i < nums.size() ; i++) {
                if (nums[i]==0) {
                    czero++;
                }
                else if (nums[i]==1) {
                    cone++;
                    
                }
                else {
                    ctwo++;
                }
                
                
            }
            int index =  0;
            
            while (czero--) {
                nums[index] = 0;
                index++;
            }
            while (cone--) {
                nums[index] = 1;
                index++;
            }
            while (ctwo--) {
                nums[index] = 2;
                index++;
            }
            
        }
    void DutchNationalFlagAlgorithm(vector <int> &a) {
            int low = 0;
            int mid = 0;
            int high = a.size()-1
            
            while (mid < high) {
                
            }
        }
};

int main() {
  
    
    Solution sol;
    
    vector <int> zot = {0,2,1,1,1,2,2,2,0,0,0,2,1};
    
    sol.sortZeroOneTwo(zot);
    
    for (int num : zot) {
        cout << num << " ";
    }

    
    
    return 0;
}
