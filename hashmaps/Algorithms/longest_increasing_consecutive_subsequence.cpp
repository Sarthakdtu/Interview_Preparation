
int longest_increasing_consecutive_subsequence(int arr[], int n){
	map<int, int> len;
	for(int i=0;i<n;i++){
		if(len[arr[i] - 1] == 0){
			//choice 1: to start its own subsequence
			len[arr[i]] = 1;
		}
		else{
			//choice 2: to get added into a prev subseq
			len[arr[i]] = len[arr[i]-1] + 1;
		}
	}
	int max_len = 0;
	// int curr = 0;
	for(auto itr=len.begin();itr!=len.end();itr++){
		max_len = max(max_len, itr->second);
	}
	return max_len;
}