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

struct edge{
	int s;
	int d;
	int cost;
};

int main(){
	sarthak();
	int v, e;
	cin>>v>>e;
	vector<edge> edge_list;
	for(int i=0;i<e;i++){
		int s, d, c;
		cin>>s>>d>>c;
		edge_list.push_back({s, d, c});
	}

	int* dist = new int[v];
	for(int i=0;i<v;i++)
		dist[i] = INT_MAX;

	dist[0] = 0;
	//V-1 iterations
	for(int i=0;i<v-1;i++){
		for(int j=0;j<edge_list.size();j++){
			edge curr = edge_list[j];
			if(dist[curr.s] != INT_MAX){
				int u = curr.d;
				if(dist[curr.s] + curr.cost < dist[u]){
					dist[u] = dist[curr.s] + curr.cost;
				}
			}
		}
	}
	bool answer = true;
	//Vth iteration
	for(int i=0;i<edge_list.size();i++){
		edge curr = edge_list[i];
		int u = curr.d;
		if(dist[curr.s] + curr.cost < dist[u]){
				answer = false;
				cout<<"Negative Cycle exists"<<endl;
				break;
		}
	}
	return 0;
}