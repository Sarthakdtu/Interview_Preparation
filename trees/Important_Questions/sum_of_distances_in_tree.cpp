//https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:

	int relative_bfs(int n, int s, vector<vector<int> > &tree){
		queue<pair<int, int> > q;
		vector<bool> vis(n, false);
		int sum = 0;
		q.push({s, 0});
        vis[s] = true;
		while(!q.empty()){
			pair<int, int> curr = q.front();
			sum += curr.second;
			q.pop();
			for(int i=0;i<tree[curr.first].size();i++){
				int child = tree[curr.first][i];
				if(vis[child])
					continue;
				q.push({child, curr.second+1});
				vis[child] = true;
			}
		}
		return sum;
	}

	void count_nodes(int s, vector<vector<int> > &tree, vector<int> &num_nodes, vector<bool> &vis){
		vis[s] = true;
		for(int i=0;i<tree[s].size();i++){	
			int child = tree[s][i];
			if(vis[child])
				continue;
			count_nodes(child, tree, num_nodes, vis);
			num_nodes[s] += num_nodes[child];
		}
	}

	void calc_distance(int n, int s, vector<vector<int> > &tree, vector<int> &distance, vector<int> &num_nodes, vector<bool> &vis){
		vis[s] = true;
		for(int i=0;i<tree[s].size();i++){
			int child = tree[s][i];
			if(vis[child])
				continue;
        	int lost_nodes = num_nodes[child];
        	int gained_nodes = n - lost_nodes;
        	distance[child] = distance[s] - lost_nodes + gained_nodes;
        	calc_distance(n, child, tree, distance, num_nodes, vis);
        }
	}

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> num_nodes(n, 1);
        vector<int> v;
        vector<vector<int> > tree(n, v);
        vector<int> distance(n, 0);
        vector<bool> vis(n, false);

        for(int i=0;i<edges.size();i++){
        	tree[edges[i][0]].push_back(edges[i][1]);
        	tree[edges[i][1]].push_back(edges[i][0]);
        }

        count_nodes(0, tree, num_nodes, vis);
        
        int sum = relative_bfs(n, 0, tree);
        vis = vector<bool>(n, false);
        distance[0] = sum;
        calc_distance(n, 0, tree, distance, num_nodes, vis);
        
        return distance;
    }
};