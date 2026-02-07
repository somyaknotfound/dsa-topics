#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Method 1: Using extra space
	string removeSubstring(string &s, string &sub) {


		// Your code here

		while (s.length()!=0 && s.find(sub) < s.length()) {
			s.erase(s.find(sub), sub.length());
		}


		return s;
	}

	// Method 2: In-place removal (optimal)
	void removeSubstringOptimal(string &str, string &sub) {
		// Your code here
		int i = 0;
		int j = 0;
		
		while (j < str.length() )  {
		    bool match = true;
		    
		    
		    if (j+ sub.length() <= str.length()) {
		        for (int k = 0 ; k < sub.length() ; k++) {
		            if (str[j+k] != sub[k]) {
		                match = false;
		                break;
		            }
		        }
		    } else {
		        match = false;
		    }
		    
		    if (match) {
		        j+= sub.length();
		        
		    } else {
		        str[i] = str[j];
		        i++;
		        j++;
		    }
		    
		    
		}
		
		str.resize(i);
		

	}
};

int main() {
	Solution sol;

	// Test case 1
	string s1 = "HelloWorldHello";
	string sub1 = "Hello";
	cout << "Original: " << s1 << endl;
	sol.removeSubstringOptimal(s1, sub1);
	cout << "Modified: " << s1 << endl;

	// Test case 2
	string s2 = "aaaabaaaa";
	string sub2 = "aa";
	cout << "\nOriginal: " << s2 << endl;
	cout << "Modified: " << sol.removeSubstring(s2, sub2) << endl;

	// Test case 3
	string s3 = "abcdefabcdefabc";
	string sub3 = "abc";
	cout << "\nOriginal: " << s3 << endl;
	sol.removeSubstringOptimal(s3, sub3);
	cout << "Modified: " << s3 << endl;

	return 0;
}
