#include<bits/stdc++.h>
using namespace std;

void dfs_util(int source, vector<int> adj[], bool vis[]){

	vis[source] = true;
	for(int i=0;i<adj[source].size();i++){
		int v = adj[i];
		if(!vis[v]){
			dfs_util(v, adj, vis);
		}
	}
}

void dfs(int source, vector<int> adj[], stack<int> &stk, bool vis[]){

	vis[source] = true;
	for(int i=0;i<adj[source].size();i++){
		int v = adj[i];
		if(!vis[v]){
			dfs(v, adj, stk, vis);
		}
	}
	stk.push(source);
}

int kosaraju(int v, vector<int> adj[]){
	stack<int> stk;
	bool vis[v];
	memset(vis, false, sizeof(vis));
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i, adj, stk, vis);
		}
	}

	vector<int> rev[v];
	for(int i=0;i<v;i++){
		for(int j =0;j<adj[i].size();j++){
			int s, d;
			s = i;
			d = adj[i][j];
			rev[d].push_back(s);
		}
	}
	int comps = 0;
	memset(vis, false, sizeof(vis));
	while(!stk.empty()){
		int s = stk.top();
		stk.pop();
		if(vis[s])
			continue;
		comps++;
		dfs_util(s, rev, vis);
	}
	return comps;
}



int main(){
	int v, e;
	
	cin>>v>>e;
	
	vector<int> adj[v];
	
	for(int i=0;i<e;i++){
		int s, d;
		cin>>s>>d;
		adj[s].push_back(d);
	}

	int ans = kosaraju(v, adj);
	cout<<ans;
	return 0;
}