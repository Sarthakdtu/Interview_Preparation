//https://leetcode.com/problems/01-matrix/submissions/
struct val{
    int r;
    int c;
    int cost;
};

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    queue<val> q;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int> > ans;
    vector<vector<bool> > vis;
    
    for(int i=0;i<n;i++){
        vector<int> a(m, -1);
        vector<bool> f(m, false);
        vis.push_back(f);
        ans.push_back(a);
        for(int j=0;j<m;j++){
            a.push_back(-1);
            f.push_back(false);
            if(matrix[i][j] == 0){
                q.push({i, j, 0});
                vis[i][j] = true;
                ans[i][j] = 0;
            }
        }
        
    }
    
    while(!q.empty()){
        val curr = q.front();
        q.pop();
        int i = curr.r;
        int j = curr.c;
        int c= curr.cost;
        if(i+1<n && matrix[i+1][j] ==1 && !vis[i+1][j]){
            q.push({i+1, j, c+1});
            ans[i+1][j] = c+1;
            vis[i+1][j] = true;
        }
        if(i-1>=0 && matrix[i-1][j] ==1 && !vis[i-1][j]){
            q.push({i-1, j, c+1});
            ans[i-1][j] = c+1;
            vis[i-1][j] = true;
        }
        if(j+1<m && matrix[i][j+1] ==1 && !vis[i][j+1]){
            q.push({i, j+1, c+1});
            ans[i][j+1] = c+1;
            vis[i][j+1] = true;
        }
        if(j-1>=0 && matrix[i][j-1] ==1 && !vis[i][j-1]){
            q.push({i, j-1, c+1});
            ans[i][j-1] = c+1;
            vis[i][j-1] = true;
        }
    }
    return ans;
}