class Solution {
public:
    
    int find(int x, int *parent){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }
    
    bool merge(int x, int y, int *parent, int* rank){
        int px = find(x, parent);
        int py = find(y, parent);
        if(px!=py){
            if(rank[px] > rank[py])
                parent[py] = px;
            else if(rank[py] > rank[px])
                parent[px] = py;
            else{
                parent[px] = py;
                rank[py]++;
            }
            return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int *parent = new int[n];
        int *rank = new int[n];
        
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i=0;i<n;i++){
            int s, d;
            s = edges[i][0];
            d = edges[i][1];
            if(!merge(s-1, d-1, parent, rank))
                return edges[i];
        }
        return edges[n-1];
    }
};