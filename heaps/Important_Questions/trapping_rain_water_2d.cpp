struct node{
	int r;
	int c;
	int h;
};
struct Compare {
    bool operator()(node const& p1, node const& p2){
        return p1.h < p2.h;
    }
};

bool safe(int r, int c, int n, int m){
	if(r <0 ||c<0 || r>=n || c>=m)
		return false;
	return true;
}

class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        bool vis[n][m];
        for(int i=0;i<n;i++)
        	for(int j=0;j<m;j++)
        		vis[i][j] = false;

        priority_queue<node, vector<node>, Compare> pq;

        for(int i=0;i<n;i++){
        	vis[i][0] = true;
        	vis[i][m-1] = true;
        	pq.push({i, 0, height[i][0]});
        	pq.push({i, m-1, height[i][m-1]});
        }

        for(int i=1;i<m-1;i++){
        	vis[0][i] = true;
        	vis[n-1][i] = true;
        	pq.push({0, i, height[0][i]});
        	pq.push({n-1, i, height[n-1][i]});
        }
        int ans = 0;
        int r, c;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while(!pq.empty()){
        	node curr = pq.top();
        	pq.pop();
        	r = curr.r;
        	c = curr.c;
        	for(int i=0;i<4;i++){
        		r = curr.r + dr[i];
        		c = curr.c + dc[i]
        		if(safe(r, c, n, m) && !vis[r][c]){
        			vis[r][c] = true;
        			if(curr.h <= height[r][c]){
        				pq.push({r, c, height[r][c]});
        			}
        			else{
        				ans += curr.h - height[r][c];
        				pq.push({r, c, curr.h});
        			}
        		}
        	}
        }
        return ans;
    }
};