// User function template for C++
class Solution {
  public:

    int shortestDistance(vector<string> &s, string word1, string word2) {
        // Your code goes here
        int last1 = -1 ;
        int last2 = -1 ;
        int minDist = INT_MAX;
        
        for (int j = 0; j < s.size() ; j++) {
            if (s[j] == word1) {
                last1 = j;
            } 
            if (s[j] == word2) {
                last2 = j;
            }
            
            if (last1 != -1 && last2 !=-1) {
            
            minDist = min(abs(last2-last1) , minDist);
        }
            
        }
        
        return minDist;
        
        
        
        
        
    }
};
