
int lcs(vector<int> arr){
	int max_elt, min_elt;
	int n = arr.size();
	int ep = 0;
	int len = 0;
	for(int sp=0;sp<n;sp++){
		max_elt = arr[sp];
		min_elt = arr[ep];
		for(int ep=sp;ep<n;ep++){
			max_elt = max(max_elt, arr[ep]);
			min_elt = min(min_elt, arr[ep]);
			int diff_len = max_elt - min_elt + 1;
			int curr_len = ep - sp + 1;
			if(curr_len == diff_len)
				len = max(len, curr_len);
		}
	}
	return len;
}