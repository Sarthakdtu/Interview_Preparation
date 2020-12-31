void dfs(int r, int c, vector<vector<int>>& arr, int n, int m){
	arr[r][c] = 0;
	if(r+1<n && arr[r+1][c]==1)
		dfs(r+1, c, arr, n, m);
	if(c+1<m && arr[r][c+1]==1)
		dfs(r, c+1, arr, n, m);
	if(r-1>-1 && arr[r-1][c]==1)
		dfs(r-1, c, arr, n, m);
	if(c-1>-1 && arr[r][c-1]==1)
		dfs(r, c-1, arr, n, m);
}


int numEnclaves(vector<vector<int>>& arr) {
	int n = arr.size();
	int m = arr[0].size();
    cout<<n<<m;
	for(int i=0;i<n;i++){
		if(arr[i][0] == 1)
			dfs(i, 0, arr, n, m);
		if(arr[i][m-1] == 1)
			dfs(i, m-1, arr, n, m);
	}
    cout<<n<<m;
	for(int j=0;j<m;j++){
		if(arr[0][j] == 1)
			dfs(0, j, arr, n, m);
		if(arr[n-1][j] == 1)
			dfs(n-1, j, arr, n, m);
	}
	int count = 0;
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(arr[i][j] == 1){
				count++;
			}
		}
	}
	return count;

}