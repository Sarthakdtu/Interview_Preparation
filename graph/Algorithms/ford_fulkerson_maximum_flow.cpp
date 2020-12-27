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

bool bfs(int v, int **graph, int *parent, int source, int sink){
	for(int i=0;i<v;i++)
		parent[i] = -1;

	bool *visited = new bool[v]();
	queue<int> q;

	q.push(source);
	visited[source] = true;
	parent[source] = source;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nbr=0;nbr<v;nbr++){
			if(!visited[nbr] && graph[u][nbr] > 0){
				visited[nbr] = true;
				parent[nbr] = u;
				q.push(nbr);
			}
		}
	}

	if(parent[sink] != -1)
		return true; //path exists
	return false;
}

int main(){
	sarthak();
	int v, e;
	cin>>v>>e;
	int **graph = new int*[v];
	for(int i=0;i<v;i++)
		graph[i] = new int[v]();

	for(int i=0;i<e;i++){
		int s, d;
		cin>>s>>d;
		s--;d--;
		cin>>graph[s][d];
	}

	int ans = 0;
	int *parent = new int[v];
	int source = 0;
	int sink = v-1;
	int ni = 0;
	while(bfs(v, graph, parent, source, sink)){
		int min_cost = INT_MAX;
		//path traversal
		for(int u=sink; u!=source; u=parent[u]){
			int p = parent[u];
			min_cost = min(min_cost, graph[p][u]);
		}
		ans += min_cost;
		//min edge capacity reduction
		for(int u=sink; u!=source; u=parent[u]){
			int p = parent[u];
			graph[p][u] -= min_cost;
			graph[u][p] += min_cost;  
		}
	}
	cout<<ans<<endl;
    return 0;
}