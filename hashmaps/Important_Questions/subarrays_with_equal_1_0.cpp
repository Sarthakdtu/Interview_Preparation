long long int countSubarrWithEqualZeroAndOne(int arr[], int n){
	long long int pre1[n];
	long long int pre0[n];
	unordered_map<int, int> occ;
	long long int count = 0;
	pre1[0] = 0;
	pre0[0] = 0;
	if(arr[0] == 0)
		pre0[0]++;
	else
		pre1[0]++;
	for(int i=1;i<n;i++){
		pre0[i] = pre0[i-1];
		pre1[i] = pre1[i-1];
		if(arr[i] == 0)
			pre0[i]++;
		else
			pre1[i]++;
	}
	occ[0] = 1;
	for(int j=0;j<n;j++){
		int diff = pre0[j] - pre1[j];
		count += occ[diff];
		occ[diff]++;
	}
	return count;
}