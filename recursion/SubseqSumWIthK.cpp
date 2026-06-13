void subSeqSumK(vector <int> &ds , int ind , int arr[] ,int n , int varsum , int target) {
    if (ind == n) {
        if (varsum == target) {
            for (int it : ds) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    
    ds.push_back(arr[ind]);
    varsum+=arr[ind];
    subSeqSumK(ds,ind+1,arr,n,varsum,target);
    ds.pop_back();
    varsum-=arr[ind];
    subSeqSumK(ds,ind+1,arr,n,varsum,target);
    
    
}








int main() {
    
    
    
    vector <int> ds;
    int arr[] =  {3,1,2};
    
    int check[] = {1,2,1};
    
    subSeqSumK(ds,0,check,3,0,2);
    
    
    
    
    return 0;
}
