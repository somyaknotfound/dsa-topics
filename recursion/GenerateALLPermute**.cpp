class Solution {
public:
    void Permute(string &s,string &temp , vector <string> &ans , vector <bool> &used) {
        if (temp.length() == s.size()) {
            ans.push_back(temp);
            return;
        }
       //at each index use the state used to check if it has been used or not 
      // to check if unique perms add if condition with that if (i> 0 && s[i] != s[i-1] && !used[i-1] continue
        for (int i = 0 ; i < s.size() ; i++) {
            if (used[i]) {
                continue;
            }

            temp.push_back(s[i]);
            used[i] = true;

            Permute(s,temp , ans ,used);
            used[i] = false;
            temp.pop_back();

        }

    }



    vector<string> permuteUnique(string s) {
        // Your code goes here
        vector <string> ans;

        string temp = "";

        vector <bool> used(s.size() , false);

        // sort(s.begin() , s.end());

        // sort(s.begin() , s.end());


        Permute(s ,temp, ans , used);

        return ans;

    }
};
