
void dfs(int r, int c, vector<vector<int>>& arr, int n, int m, string &pat){
	arr[r][c] = 0;

	if(r+1<n && arr[r+1][c]==1){
		pat = pat + "D";
		dfs(r+1, c, arr, n, m, pat);
	}
	if(c+1<m && arr[r][c+1]==1){
		pat = pat + "R";
		dfs(r, c+1, arr, n, m, pat);
	}
	if(r-1>-1 && arr[r-1][c]==1){
		pat = pat + "U";
		dfs(r-1, c, arr, n, m, pat);
	}
	if(c-1>-1 && arr[r][c-1]==1){
		pat = pat + "L";
		dfs(r, c-1, arr, n, m, pat);
	}
	pat += "X";
}
   

int numberofDistinctIslands(vector<vector<int>>& arr) {
	int n = arr.size();
	int m = arr[0].size();
	int count = 0;
	unordered_map<string, int >vis;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==1){
				string pat = "";
				dfs(i, j, arr, n, m, pat);
				if(vis[pat] == 0){
					count++;
					vis[pat] = 1;
				}
			}
		}
	}
	return count;
}