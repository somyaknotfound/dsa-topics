#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int MaxSubArrayBrute(vector  <int>&nums) {
        int maxi  = INT_MIN;
        
        for (int i = 0 ; i < nums.size() ; i++)  {
            for (int j = i ;  j < nums.size() ; j++) {
                int sum = 0;
                for (int k = i ; k <= j ; k++) {
                    sum+=nums[k];
                }
                maxi = max(sum,maxi);
            }
            
        }
        
        
        return maxi;
        
        
        
    }
    
    int MaxSubArrayBetter(vector <int> &nums) {
        
        int maxi = INT_MIN;
        
        for(int i = 0 ;  i < nums.size() ; i++) {
            int sum = 0;
            for (int j = i ; j< nums.size() ; j++) {
                sum+=nums[j];
                
                maxi = max(maxi,sum);
            }
        }
        
        
        return maxi;
    }
    
    
    int MaxSubARrayOptimal(vector <int> &nums) {
        //kadane algorithm
        
        long long maxi = LLONG_MIN;
        
        long long sum = 0;
        
        for (int i =  0 ; i < nums.size();i++) {
            sum += nums[i];
            
            
            if (sum > maxi) {
                maxi = sum;
            }
            
            if (sum < 0) {
                sum = 0;
                
                
            }
        }
        
        return maxi;
        
        
        
      
    }

    int MaxSubARrayOptimalPrint(vector <int> &nums) {
        //kadane algorithm
        
        long long maxi = LLONG_MIN;
        
        long long sum = 0;
        
        int start = 0;
        
        int ansStart = -1 ;
        int ansEnd = -1 ;
        
        
        
        for (int i =  0 ; i < nums.size();i++) {
            
            
            if (sum == 0) {
                start = i;
            }
            
            sum += nums[i];
            
            if (sum > maxi) {
                maxi = sum;
                ansStart  = start;
                ansEnd = i;
            }
            
            if (sum < 0) {
                sum = 0;
                
                
            }
        }
        
        
        cout << "The Maximum Subarray is: [";
        for (int i = ansStart ; i <= ansEnd ; i++) {
            cout<< nums[i]<< ", ";
        }
        cout << "]"<<endl;
        
        
        return maxi;
        
        
        
        
        
        
        
    }
    
    
  
  
    
};




int main() {
    
    
    Solution sol;
    
    
    vector <int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    
    int MaxSum = sol.MaxSubARrayOptimal(arr);
    
    
    cout<< "Maximum contigious subarray sum "<<MaxSum;
    
    
    return 0;
}
