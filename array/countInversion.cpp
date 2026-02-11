#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
    int CountInversionBrute(vector <int> &arr , int n) {
        int cnt = 0;
        
        for (int i = 0 ; i < n ; i++) {
            for (int j = i+1 ;  j < n ; j++) {
                if (arr[i] > arr[j]) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
    int merge(vector <int> &arr , int low , int mid , int high) {
        vector <int> temp;
        
        int left = low;
        int right = mid+1;
        
        int cnt = 0;
        
        
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                
                cnt+= (mid - left + 1);
                right++;
            }
        }
        
        while(left <= mid) {
        temp.push_back(arr[left]);   // ✓ Use 'left'
        left++;                       // ✓ Increment 'left'
}
        
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for (int i = low ;  i <=high ; i++) {
            arr[i] = temp[i-low];
        }
        
        return cnt;
    }
    
    int mergeSort(vector<int> &arr , int low , int high) {
        int cnt = 0;
        
        if (low>=high) return cnt;
        
        int mid = (low+high)/2;
        
        cnt+= mergeSort(arr,low,mid);
        
        cnt+= mergeSort(arr,mid+1,high);
        
        cnt+= merge(arr,low,mid, high);
        
        return cnt;
    }
    
    int CountInversionOptimal(vector <int> &arr , int n) {
        return mergeSort(arr,0,n-1);
    }
    
    
};



int main() {
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();
    Solution sol;
    int cnt = sol.CountInversionOptimal(a,n);
    cout << "The number of inversions is: " << cnt << endl;
    
    
    
    return 0;
}
