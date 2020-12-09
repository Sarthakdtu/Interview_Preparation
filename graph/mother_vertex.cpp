



void dfs(int source, vector<int> graph[], stack<int> &stk, bool vis[]){
	vis[source] = true;

	for(int i=0;i<graph[source].size();i++){
		int v = graph[source][i];
		if(!vis[v]){
			dfs(v, graph, stk, vis);
		}
	}
	stk.push(source);
}

void reach(int source, vector<int> graph[], bool vis[], int &count){
	vis[source] = true;
	count++;
	for(int i=0;i<graph[source].size();i++){
		int v = graph[source][i];
		if(!vis[v]){
			reach(v, graph, vis, count);
		}
	}
}

int findMother(int v, vector<int> graph[]){
	bool vis[v];
	memset(vis, false, sizeof(vis));
	stack<int> stk;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i, graph, stk, vis);
		}
	}

	memset(vis, false, sizeof(vis));
	int mv = stk.top();
	int count = 0;
	reach(mv, graph, vis, count);
	if(count == v){
		return mv;
	}
	return -1;
}