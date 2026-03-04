#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int firstLastOcc(vector <int> &a , int key) {
        int n = a.size();
        int res = -1;
        for (int i = n-1 ; i>=0 ; i--) {
            if (a[i] == key) {
                res = i;
                break;
            }
        }
        
        return res;
        
    }
    
    int optimizedBinarySearch(vector <int> &v ,int key ) {
        int n = v.size();
        
        int l  = 0 ;
        int h = n-1;
        int res = -1;
        
        while(l<= h) {
            int mid = l + (h-l)/2;
            
            if (v[mid] == key) {
                res = mid;
                l = mid+1;
            }
            
            else if(key < v[mid]) {
                h = mid - 1;
                
            } else {
                l = mid+1;
            }
        }
        
        return res;
    }

vector<int> searchRange(vector<int>& nums, int key) {
        int l = 0;
        int h = nums.size() -1;
        int f = -1;
        int e = -1;
        

        while (l <=h) {
            int mid = l + (h-l)/2;

            if (nums[mid]== key) {
                e = mid;
                l = mid+1;

            }
            else if( key < nums[mid]) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        l = 0;
        h = nums.size() - 1;
        while (l <=h) {
            int mid = l + (h-l)/2;

            if (nums[mid]== key) {
                f = mid;
                h = mid-1;

            }
            else if( key < nums[mid]) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        return {f,e};
    }
};




int main() {
 
  
  // set key to search
  int key = 13;
  
  vector<int> v = {3, 4, 13, 13, 13, 20, 40};
  
  Solution sol;
  
  cout << sol.optimizedBinarySearch(v,key) <<endl;
  // exit
  return 0;
}
