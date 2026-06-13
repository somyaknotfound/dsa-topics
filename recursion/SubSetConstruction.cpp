class Solution {
  public:
    void subseq (vector<int>& arr , vector <int> &ds , int ind , vector <vector <int>> & ans) {
        if (ind == arr.size()) {
            ans.push_back(ds);
            return;
        }


      
        //pick  
        ds.push_back(arr[ind]);
        subseq(arr,ds,ind+1,ans);

        //not pick
        ds.pop_back();
        subseq(arr,ds,ind+1,ans);
        
    }
  
  
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        
        vector <vector <int>> ans;
        vector <int> ds;
        
        subseq(arr ,ds,0 , ans);
        
        return ans;
        
        
        
        
        
    }
};
