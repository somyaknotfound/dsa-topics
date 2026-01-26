#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    public:
        vector <vector <int>> fourSum(vector <int> &arr , int target) {
            int n = arr.size();
            
            set <vector <int>> st;
            
            for (int i = 0 ; i < n ; i++) {
                for (int j = i+1 ; j < n ; j++) {
                    for (int k = j+1 ; k < n ; k++) {
                        for (int l = k+1 ; l< n ;l++) {
                            long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                            
                            if (sum == target) {
                                vector <int> temp = {arr[i] , arr[j] , arr[k] , arr[l]};
                                sort(temp.begin() , temp.end());
                                
                                st.insert(temp);
                            }
                        }
                    }
                }
            }
            
            return vector <vector <int>> (st.begin() , st.end());
        }
        
        vector <vector <int>> fourSumBetter(vector <int> &arr , int target) {
            int n = arr.size();
            
            set <vector <int>> st;
            
            for (int i = 0 ; i < n ; i++) {
                for (int j = i+1 ; j < n ;j++) {
                    set <int> hashset;
                    for (int k = j+1 ; k < n ; k++) {
                        long long fourth = (long long) target -arr[i] - arr[j] - arr[k];
                        if (hashset.count(fourth)) {
                            vector <int> temp = {arr[i] , arr[j], arr[k] , (int)fourth};
                            sort(temp.begin() , temp.end());
                            st.insert(temp);
                        }
                        
                        hashset.insert(arr[k]);
                        
                    }
                }
            }
            return vector <vector <int>> (st.begin() , st.end());
        }
        
        vector<vector<int>> fourSumOptimal(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        vector <vector <int>> ans;

        for (int i = 0 ; i < n ; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1 ; j < n ;j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = n-1;

                while (left < right) {
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++, right--;

                        while (left <right && nums[left] == nums[left-1]) left++;
                        while (left < right && nums[right] == nums[right+1]) right--;
                    }

                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }

            }
        }
        return ans;
    }
        
        
};

int main() {
    // Input array
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    // Target sum
    int target = 0;

    // Create object
    Solution obj;
    // Get all quadruplets
    vector<vector<int>> ans = obj.fourSumOptimal(arr, target);

    // Print result
    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}
