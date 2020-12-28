//https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    
    struct edge{
        int i;
        int j;
        int c;
    };
        
    void dfs(vector<vector<int> >& arr, int r, int c, queue<edge> &q,  vector<vector<bool> > &vis){
        
        if(r>=arr.size()||r<0 || c>=arr.size()||c<0 || arr[r][c] == 0||arr[r][c]==2)
            return ;
        
        q.push({r, c, 0});
        vis[r][c] = true;
        arr[r][c] = 2;
        dfs(arr, r+1, c, q, vis);
        dfs(arr, r-1, c, q, vis);
        dfs(arr, r, c-1, q, vis);
        dfs(arr, r, c+1, q, vis);
    }
    
    int shortestBridge(vector<vector<int> >& arr) {
        int n = arr.size();
        int r=-1, c=-1;
        vector<vector<bool> >vis(n);
        for(int i=0;i<n;i++){
            vis[i] = vector<bool> (n, false);
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    r = i;
                    c = j;
                }
            }
        }
        
        queue<edge> q;
        dfs(arr, r, c, q, vis);
        
        
        int ans= n*n;
        
        // q.push({r, c, 0});
        
        while(!q.empty()){
            edge curr = q.front();
            q.pop();
            r = curr.i;
            c = curr.j;
                       
            
            int cost = 0;
            if(r+1<arr.size() && !vis[r][c+1]){
                if(arr[r+1][c] == 1){
                    ans = min(ans, curr.c);
                }
                else{
                    q.push({r+1, c, curr.c+1});
                    vis[r+1][c] = true;
                }
            }
            
            if(c+1<arr.size() && !vis[r][c+1]){
                if(arr[r][c+1] == 1){
                    ans = min(ans, curr.c);
                }
                else{
                    q.push({r, c+1, curr.c+1});
                    vis[r][c+1] = true;
                }
            }
            
            if(c>0 && !vis[r][c-1]){
                if(arr[r][c-1] == 1){
                   ans = min(ans, curr.c);
                }
                else{
                    q.push({r, c-1, curr.c+1});
                    vis[r][c-1] = true;
                }
            }
            
            if(r>0 && !vis[r-1][c]){
                if(arr[r-1][c] == 1){
                    ans = min(ans, curr.c);
                }
                else{
                    q.push({r-1, c, curr.c+1});
                    vis[r-1][c] = true;
                }
            }           
        }
        return ans;
    }
};
