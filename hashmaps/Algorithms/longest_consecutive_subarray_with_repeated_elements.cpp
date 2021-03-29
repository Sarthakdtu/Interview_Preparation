
int lcs(vector<int> arr){
	int max_elt, min_elt;
	int n = arr.size();
	int ep = 0;
	int len = 0;
	map<int, int> vis;
	for(int sp=0;sp<n;sp++){
		vis[arr[sp]] = 1;
		max_elt = arr[sp];
		min_elt = arr[ep];
		for(int ep=sp+1;ep<n;ep++){
			if(vis[arr[ep]] == 1)
				break;
			vis[arr[ep]] = 1;
			max_elt = max(max_elt, arr[ep]);
			min_elt = min(min_elt, arr[ep]);
			int diff_len = max_elt - min_elt + 1;
			int curr_len = ep - sp + 1;
			if(curr_len == diff_len)
				len = max(len, curr_len);
		}
		vis.clear();
	}
	return len;
}