#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool CanWeAllocate(vector<int>&nums , int barrier, int m) {
            int AlocStud = 1;
            int pages = 0;
            
            for (int i = 0 ; i <nums.size() ; i++) {
                if (nums[i] > barrier) return false;
                
                if (nums[i] + pages > barrier) {
                    AlocStud++;
                    pages = nums[i];
                } else {
                    pages+=nums[i];
                }
            }
            return AlocStud<=m;
        }
    
    
    // low is max element 
    // compare nums[i] with barrier
    // alocStud <= m 
    // if can allocate reduce towards the lower half of search namespace
    
        int findPages(vector <int> &nums , int m) {
            if (m>nums.size()) return -1;
            
            int low = *max_element(nums.begin() , nums.end());
            int high = accumulate(nums.begin() , nums.end() , 0);
            int res = -1;
            
            while (low<=high) {
                int mid = (high+low)/2;
                
                if (CanWeAllocate(nums,mid,m)) {
                    res = mid;
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
            
            return res;
        }
};


/*
using namespace std;

bool CanWeAllocate(vector<long long>& books,
                   long long barrier,
                   long long M) {
    
    long long StudAloc = 1;
    long long pages = 0;

    for (int i = 0; i < books.size(); i++) {
        if (books[i] > barrier)
            return false;

        if (pages + books[i] > barrier) {
            StudAloc++;
            pages = books[i];
        } 
        else {
            pages += books[i];
        }
    }

    return StudAloc <= M;
}

long long allocateBooks(vector<long long>& books, int N, int M) {
    if (M > N) return -1;

    long long low = *max_element(books.begin(), books.end());
    long long high = accumulate(books.begin(), books.end(), 0LL);

    long long res = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (CanWeAllocate(books, mid, M)) {
            res = mid;
            high = mid - 1;   // try smaller answer
        } 
        else {
            low = mid + 1;    // need larger barrier
        }
    }

    return res;
}
*/


int main() {
    vector<int> arr = {12,34,67,90};
    int m =2;
    
    Solution sol;
    
    int ans = sol.findPages(arr,m);
    
    cout << ans << endl;
    
    
     
    
    
    
    
    return 0;
}
