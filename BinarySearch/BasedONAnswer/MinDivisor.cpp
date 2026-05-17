#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

	int checkDiv(vector<int>& nums, int d) {
		int sum = 0;

		for(int num : nums) {
			sum += (num + d - 1) / d;
		}

		return sum;
	}

	int smallestDivisor(vector<int>& nums, int threshold) {

		int low = 1;
		int high = *max_element(nums.begin(), nums.end());

		for(int div = low; div <= high; div++) {

			if(checkDiv(nums, div) <= threshold) {
				return div;
			}
		}

		return -1;
	}

	int smallestDivisorOpt(vector<int>& nums, int threshold) {
		int low = 1;
		int high = *max_element(nums.begin(), nums.end());
		int ans = -1;
		while (low <= high) {
			int mid = (low+high)/2;
			if (checkDiv(nums,mid) <= threshold) {
				ans = mid;
				high = mid-1;
			}
			else {
				low = mid+1;
			}
		}
		return ans;
	}
};



int main() {
	vector<int> arr = {1, 2, 3, 4, 5};
	int limit = 8;

	Solution obj;
	int ans = obj.smallestDivisorOpt(arr, limit);

	cout << "The minimum divisor is: " << ans << "\n";
	return 0;
}
