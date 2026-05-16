#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate total hours for given speed
    int calculateTotalHours(vector<int>& a, int hourly) {
        int totalHours = 0;
        for (int pile : a) {
            // Add hours using ceil
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& a, int h) {
        // Find maximum pile size
        int maxVal = *max_element(a.begin(), a.end());

        // Try every possible speed
        for (int i = 1; i <= maxVal; i++) {
            int hours = calculateTotalHours(a, i);

            // If hours fit within h
            if (hours <= h) {
                return i;
            }
        }
        return maxVal;
    }


    class Solution {
public:

    long long calculateTotalHours(vector<int>& nums, long long speed) {
        long totalH = 0;

        for (long bananas : nums) {
            totalH += (bananas + speed - 1) / speed;
        }

        return totalH;
    }

    long long minimumRateToEatBananas(vector<int>& nums, long long h) {

        long long low = 1;
        long long high = *max_element(nums.begin(), nums.end());

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(nums, mid);

            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

    
};

int main() {
    // Input array
    vector<int> a = {3, 6, 7, 11};
    // Hours allowed
    int h = 8;

    Solution obj;
    cout << obj.minEatingSpeed(a, h);
    return 0;
}
    
