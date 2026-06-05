class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        if (s1 == s2) {
            return 1;
        }
        
        string temp = "";
        int count = 0;
        
        int req = (s2.size() + s1.size() -1 )/ s1.size();
        
        for (int i = 0 ; i < req ; i++) {
            temp+=s1;
        }
        
        if (temp.find(s2) != string::npos) {
            return req;
        }
        
        temp+=s1;
        
        if (temp.find(s2) != string::npos) {
            return req+1;
        }
        
        
        return -1;
    }
};
