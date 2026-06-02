#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double MedianOfArrays(vector <int> &a, vector <int> &b) {
		int n1 = a.size();
		int n2 = b.size();
		vector <int> ans;

		int i = 0 ;
		int j = 0;

		while (i < n1 && j < n2) {
			if (a[i] < b[j]) ans.push_back(a[i++]);
			else ans.push_back(b[j++]);
		}

		while (i < n1) ans.push_back(a[i++]);
		while (j < n2) ans.push_back(b[j++]);


		int n = n1+ n2;

		if (n%2==1) {
			return ans[n/2];
		}

		return (double) ((double) (ans[n/2]) + (double)(ans[n/2-1])) / 2.0;
	}


	double MedianBetter(vector <int> a,vector <int> b) {
		int n1 = a.size();
		int n2 = b.size();

		int n = n1 + n2;

		int ind2 = n/2;
		int ind1 = n/2 - 1;

		int ind1el = -1;
		int ind2el = -1;
		int cnt = 0;

		int i = 0;
		int j = 0;

		while ( i< n1 && j < n2) {
			if (a[i] < b[j]) {
				if (cnt == ind1) ind1el = a[i];
				if (cnt == ind2) ind2el = a[i];
				cnt++;
				i++;
			} else {
				if (cnt == ind1) ind1el = b[j];
				if (cnt == ind2) ind2el = b[j];
				cnt++;
				j++;
			}
		}

		while (i < n1) {
			if (cnt == ind1) ind1el = a[i];
			if (cnt == ind2) ind2el = a[i];
			cnt++;
			i++;
		}

		while (j < n2) {
			if (cnt == ind1) ind1el = b[j];
			if (cnt == ind2) ind2el = b[j];
			cnt++;
			j++;
		}
		
		if (n%2 ==1) {
		    return ind2el;
		}
		
		return (double)((ind2el + ind1el) / 2.0);

	}
};


int main() {

	vector <int> a = {1,3,4,7,10,12};
	vector <int> b = {2,3,6,15};
	Solution sol;
	double ans = sol.MedianOfArrays(a,b);

	cout << ans << endl;





	return 0;
}
