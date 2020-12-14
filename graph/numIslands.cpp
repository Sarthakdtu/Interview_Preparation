
//https://leetcode.com/problems/number-of-islands/

void dfs(int r, int c, vector<vector<char>>& arr, int n, int m){
	arr[r][c] = '0';
	if(r+1<n && arr[r+1][c]=='1')
		dfs(r+1, c, arr, n, m);
	if(c+1<m && arr[r][c+1]=='1')
		dfs(r, c+1, arr, n, m);
	if(r-1>-1 && arr[r-1][c]=='1')
		dfs(r-1, c, arr, n, m);
	if(c-1>-1 && arr[r][c-1]=='1')
		dfs(r, c-1, arr, n, m);
}
   

int numIslands(vector<vector<char>>& arr) {
	int n = arr.size();
	int m = arr[0].size();
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='1'){
				dfs(i, j, arr, n, m);
				count++;
			}
		}
	}
	return count;
}