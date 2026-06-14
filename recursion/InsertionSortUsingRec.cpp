void insert(vector <int> &v, int temp) {
	if(v.size() == 0 || v[v.size() - 1] <= temp) {
	    v.push_back(temp);
		return;
	}

	int val = v[v.size() - 1];
	v.pop_back();
	insert(v,temp);
	v.push_back(val);
	return;


}

void SortUsingRec(vector <int> &v) {
	if (v.size() <=1) {
		return;
	}

	int temp = v.back();
	v.pop_back();


	SortUsingRec(v);

	insert(v,temp);
}

int main()
{
	vector<int> arr = {5, 2, 8, 1, 9, 3};

	int n = arr.size();
	
	SortUsingRec(arr);

	// 	mergeSort(arr, 0, n - 1);


	cout << "Sorted Array: ";

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
