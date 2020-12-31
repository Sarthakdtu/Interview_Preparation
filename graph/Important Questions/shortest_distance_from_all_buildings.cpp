//https://www.lintcode.com/problem/shortest-distance-from-all-buildings/description

struct edge{
	int r;
	int c;
	int d;
};
class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the shortest distance
     */
	void bfs(vector<vector<int>> &arr, int r, int c, int **count, int **dis){
		int n = arr.size();
       	int m = arr[0].size();
       	bool **vis = new bool*[n];
        for(int i=0;i<n;i++)
       		vis[i] = new bool[m]();
       	queue<edge> q;
       	q.push({r, c, d});

       	while(!q.empty()){
       		edge curr = q.front();
       		q.pop();
       		int i = curr.r;
       		int j = curr.c;
       		int d = curr.d;
       		//up
       		if(i>0 && arr[i-1][j] == 0 && !vis[i-1][j]){
       			vis[i-1][j] = true;
       			dis[i-1][j] += d+1;
       			count[i-1][j] += 1;
       			q.push({i-1, j, d+1}); 
       		}
       		//down
       		if(i<n-1 && arr[i+1][j] == 0 && !vis[i+1][j]){
       			vis[i+1][j] = true;
       			dis[i+1][j] += d+1;
       			count[i+1][j] += 1;
       			q.push({i+1, j, d+1}); 
       		}
       		//left
       		if(j>0 && arr[i][j-1] == 0 && !vis[i][j-1]){
       			vis[i][j-1] = true;
       			dis[i][j-1] += d+1;
       			count[i][j-1] += 1;
       			q.push({i, j-1, d+1}); 
       		}
       		//right
       		if(j<m-1 && arr[i][j+1] == 0 && !vis[i][j+1]){
       			vis[i][j+1] = true;
       			dis[i][j+1] += d+1;
       			count[i][j+1] += 1;
       			q.push({i, j+1, d+1}); 
       		}
       	}
	}

    int shortestDistance(vector<vector<int>> &arr) {
        // write your code here
       	int n = arr.size();
       	int m = arr[0].size();
       	int **count = new int*[n];
       	int **dis = new int*[n];
       	for(int i=0;i<n;i++){
       		count[i] = new int[m]();
       		dis[i] = new int[m]();
       	}

       	int num_1 = 0;
       	for(int i=0;i<n;i++){
       		for(int j=0;j<m;j++){
       			if(arr[i][j] == 1){
       				num_1++;
       				bfs(arr, i, j, count, dis);
       			}
       		}
       	}
       	int ans = INT_MAX;
       	for(int i=0;i<n;i++){
       		for(int j=0;j<m;j++){
       			if(arr[i][j] == 0 && count[i][j]==num_1){
       				ans = min(ans, dis[i][j]);
       			}
       		}
       	}

       	return ans;
    }
};