#include<iostream>
#include<set>
#include<vector>
using namespace std;




int main()
{
    // brute
    vector<int> arr = {1,1,2,2,2,3,3,3};
    // set<int> st;
    // for (int i = 0; i< arr.size(); i++) {
    //     st.insert(arr[i]);
    // }
    // int index  = 0;
    // for(auto it: st) {
    //     arr[index] = it;
    //     index++;
    // }

    // for (int i = 0;i<index;i++){
    //     cout<<arr[i]<<" ";
    // }
    // optimal
    int i = 0; 
    for (int j = 1 ; j< arr.size(); j++) {
        if (arr[j]!=arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
    }

    return 0;
}