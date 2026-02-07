#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string replaceSpaces(string &str) {
        string result = "";
        
        for (int i = 0 ; i < str.length() ; i++) {
            if (str[i] == ' ') {
                result+="@40";
                
            } else {
                result+=str[i];
            }
        }
        
        return result;
    }
    
    void replaceSpacesOptimal(string &str) {
        int spacecount = 0;
        
        for (char ch : str) {
            if (ch == ' ') spacecount++;
        }
        
        
        int oldLen = str.length();
        int newLen = oldLen + 2*spacecount;
        
        str.resize(newLen);
        
        int j = newLen-1;
        
        for (int i = oldLen-1 ; i>=0 ; i--) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '4';
                str[j--] = '@';
            } else {
                str[j--] = str[i];
            }
        }
        
        
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "Hello World";
    cout << "Original: " << s1 << endl;
    sol.replaceSpacesOptimal(s1);
    cout << "Modified: " << s1 << endl;
    
    // Test case 2
    string s2 = "Coding is fun";
    cout << "\nOriginal: " << s2 << endl;
    cout << "Modified: " << sol.replaceSpaces(s2) << endl;
    
    // Test case 3
    string s3 = "   spaces   everywhere   ";
    cout << "\nOriginal: " << s3 << endl;
    sol.replaceSpacesOptimal(s3);
    cout << "Modified: " <<  s3 << endl;
    
    return 0;
}
