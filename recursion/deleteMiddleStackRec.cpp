void solve(stack <int> &st , int k) {
    if (k == 1) {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st,k-1);
    st.push(temp);
    return;
}  
stack <int> deleteStackMid(stack <int> &st , int size) {
    if (st.size() == 0) {
        return st;
    }
    
    int k = size / 2 + 1;
    solve(st ,k);
    return st;
}



int main()
{
// 	vector<int> arr = {5, 2, 8, 1, 9, 3};

// 	int n = arr.size();
	
// 	SortUsingRec(arr);

    stack <int> st;
    st.push(4);
    st.push(1);
    st.push(6);
    st.push(3);
    st.push(9);
    st.push(2);
    
    sortstack(st);
	

    
    stack <int> midDel = deleteStackMid(st , st.size());
    
    while (!midDel.empty()) {
        cout << midDel.top() << " ";
        midDel.pop();
    }
    
    cout << endl;

	// 	mergeSort(arr, 0, n - 1);



	return 0;
}
