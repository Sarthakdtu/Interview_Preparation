#include<bits/stdc++.h>

using namespace std;

class DSU{
	int *parent;
	int *rank;
	public:

		DSU(int v){
			parent = new int[v+1];
			rank = new int[v+1];
			for(int i=0;i<v+1;i++){
				parent[i] = i;
				rank[i] = 1;
			}
		}

		int find(int x);
		void merge(int x, int y);
}

int DSU::find(int x){
	if(x == parent[x])
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void DSU::merge(int x, int y){
	int px = find(x);
	int py = find(y);
	if(px != py){
		if(rank[px] > rank[py])
			parent[py] = parent[x];
		else if(rank[px] < rank[py])
			parent[px] = py;
		else{
			parent[px] = py;
			rank[py]++;
		}
	}
}



int main(){
	int v, e;
	cin>>v>>e;

	vector<pair<int, int> > edge_list(e);
	for(int i=0;i<e;i++)
		cin>>edge_list[i];
	dsu = DSU(v);
	for(int i=0;i<e;i++){
		dsu.merge(edge_list[i].first, edge_list[i].second);
	}


	return 0;
}