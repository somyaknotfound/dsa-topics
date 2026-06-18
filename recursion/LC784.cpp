class Solution {
public:
    void Permute(string ip , string op , vector <string> &ans) {
        if (ip.length() == 0) {
            ans.push_back(op);
            return;
        }

        string op1 = op;
        string op2 = op;


        if (isalpha(ip[0])) {
            op1.push_back((char)tolower(ip[0]));
            op2.push_back((char)toupper(ip[0]));
            ip.erase(ip.begin());

            Permute(ip , op1 , ans);
            Permute(ip , op2 , ans);
        } else {
            op.push_back(ip[0]);
            ip.erase(ip.begin());
            Permute(ip , op  , ans);
        }


        
    }


    vector<string> letterCasePermutation(string s) {
        string ip = s;
        string op = "";

        vector <string> ans;
        Permute(ip , op , ans);

        return ans;

    }
};
