


vector<int> topoSort(int v, vector<int> adj[]){
	int in_degree[v];
	memset(in_degree, 0, sizeof(in_degree));
	
	for(int i=0;i<v;i++){
		for(int j=0;j<adj[i].size();j++){
		    int u = adj[i][j];
			in_degree[u]++;
		}
	}

	queue<int> q;
	for(int i=0;i<v;i++){
		if(in_degree[i] == 0){
			q.push(i);
			in_degree[i]=-1;
		}
	}
   
	int count = 0;
	vector<int> ans;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.push_back(u);
		count++;
		for(int i=0;i<adj[u].size();i++){
			int ne = adj[u][i];
			if(in_degree[ne]>0)
				in_degree[ne]--;
				
			if(in_degree[ne]==0){
				q.push(ne);
				in_degree[ne]=-1;
			}
		}
	}
	if(count!=v)
	    ans.clear();
	return ans;
}
