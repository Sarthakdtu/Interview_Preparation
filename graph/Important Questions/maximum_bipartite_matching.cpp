//https://practice.geeksforgeeks.org/problems/maximum-bipartite-matching/1

#include<bits/stdc++.h>

using namespace std;
#define pb  push_back
#define mod 1000000007
#define INF 1e18
 
typedef  long long ll;
void sarthak()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int M = 100;
int N = 100;

bool bfs(int **graph, int v, int source, int sink, int *parent){
	for(int i=0;i<v;i++)
		parent[i] = -1;
	bool *vis = new bool[v]();

	queue<int> q;
	q.push(source);
	vis[source] = true;
	parent[source] = source;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i=0;i<v;i++){
			if(!vis[i] && graph[u][i]>0){
				q.push(i);
				vis[i] = true;
				parent[i] = u;
			}
		}
	}

	if(parent[sink] != -1)
		return true;
	return false;
}



int maxflow(int **graph, int v, int source, int sink){

	int ans = 0;
	int *parent = new int[v];
	
	while(bfs(graph, v, source, sink, parent)){
		int min_cost = INT_MAX;

		for(int u=sink;u!=source;u=parent[u]){
			int p = parent[u];
			min_cost = min(graph[p][u], min_cost);
		}
		ans += min_cost;		
		for(int u=sink;u!=source;u=parent[u]){
			int p = parent[u];
			graph[p][u] -= min_cost;
			graph[u][p] += min_cost; 
		}
	}
	return ans;
}


int maxBPM(bool adj[M][N],int m,int n){
	int **graph = new int*[m+n+2]; // total nodes = m + n + source(1) + sink(1)
    for(int i=0;i<m+n+2;i++)
        graph[i] = new int[m+n+2]();

	int source = 0;
	int sink = m+n+1;
	
	for(int i=1;i<=m;i++)	//source to person
		graph[source][i] = 1;
	for(int i=m+1;i<m+n+1;i++) //job to sink
		graph[i][sink] = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			graph[i+1][j+m+1] = adj[i][j];
		}
	}
	int ans = maxflow(graph, m+n+2, source, sink);
	return ans;	
}

int main(){
	sarthak();
	int m, n;
	cin>>m>>n;
	bool graph[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	cout<<maxBPM(graph, m, n)<<endl;
    return 0;
}