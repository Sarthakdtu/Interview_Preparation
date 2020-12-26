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

int source = -1;
int timestamp = 0;
int children = 0;

bool *art_point;
int *parent;
int *disc;
int *low;
bool *visited;

void explore(int s, vector<vector<int> > &graph){
	visited[s] = true;
	disc[s] = timestamp;
	low[s] = timestamp;
	timestamp++;
	for(int i=0;i<graph[s].size();i++){		
		
		int nbr = graph[s][i];

		if(parent[s] == nbr)
			continue;

		if(visited[nbr]){
			low[s] = min(low[s], disc[nbr]);
		}
		else{
			parent[nbr] = s;
			explore(nbr, graph)
			low[s] = min(low[s], low[nbr]);
			if(s == source)
				children++;
		}

		if(disc[s] <= low[nbr] && s != source){
			art_point[s] = true;
		}

	}
}

int main(){
	sarthak();
	int v, e;
	cin>>v>>e;
	vector<vector<int > > graph(v);
	for(int i=0;i<e;i++){
		int s, d;
		cin>>s>>d;
		edge[s].push_back(d);
		edge[d].push_back(s);
	}	
	
	art_point = new bool[v]();
	parent = new int[v];
	disc = new int [v];
	low = new int[v];
	visited = new bool[v]();

	for(int i=0;i<v;i++){
		parent[i] = i;
		low[i] = i; 
		disc[i] = i;
	}

	source = 0;
	timestamp = 0;
	children = 0;
	
	explore(source, graph);

	if(children > 1)
		art_point[source] = true;

    return 0;
}