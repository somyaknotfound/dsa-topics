#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

	/*
    adarsh method
    
    lowk good

	bool left = true, right = true;

	for (int i = 0; i < n; i++) {
	if (left && s2[i] != s1[(i + 2) % n])
	    left = false;

	if (right && s2[i] != s1[(i - 2 + n) % n])
	    right = false;

	if (!left && !right)
	    return false;
	}

	return true;


	*/


	string leftRotate(string s1) {
		reverse(s1.begin(), s1.end());
		reverse(s1.begin(), s1.begin() + s1.size() - 2);
		reverse(s1.begin() + s1.size() - 2, s1.end());


		return s1;
	}

	string rightRotate(string s1) {
		reverse(s1.begin(), s1.end());
		reverse(s1.begin(), s1.begin()  + 2);
		reverse(s1.begin() + 2, s1.end());


		return s1;
	}


	bool isRotatedOptimal(string& s1, string& s2) {
		if (rightRotate(s1) == s2 || leftRotate(s1) == s2) {
			return true;
		}
		return false;
	}
};


int main() {
	string s1;
	string s2;

	cin>>s1;
	// cin>>s2;

	// reverse(s1.begin() , s1.end());
	// reverse(s1.begin(), s1.begin()+s1.size() -2);
	// reverse(s1.begin() + s1.size() -2 , s1.end());

	cout << s1.substr(2) + s1.substr(0,2)<<endl ;
	cout << s1.substr(s1.size() -2) + s1.substr(0, s1.size() -2);


}
