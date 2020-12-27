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
	ll s;
	ll d;
	ll cost;
	bool operator< (const edge& b) const{
		return (this->cost < b.cost);
	}
};


ll find(ll x, ll* parent){
	if( x == parent[x])
		return x;
	return parent[x] = find(parent[x], parent);
}

bool merge(ll x, ll y, ll* parent, ll* rank){
	ll px = find(x, parent);
	ll py = find(y, parent);
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


int main(){
	sarthak();
	int v, e;
	cin>>v>>e;

	set<edge> pq;
	ll *parent = new ll[v];
	ll *rank = new ll[v];
	for(int i=0;i<v;i++){
		parent[i] = i;
		rank[i] = 1;
	}
	for(int i=0;i<e;i++){
		ll s, d, c;
		cin>>s>>d>>c;
		s--; d--;
		pq.insert({s, d, c});
	}

	ll mst_cost = 0;
	int edge_count = 0;
	while(edge_count != v-1){
		edge curr = *(pq.begin());
		pq.erase(pq.begin());

		if(merge(curr.s, curr.d, parent, rank)){
			mst_cost += curr.cost;
			edge_count++;
		}
	}
	cout<<mst_cost<<endl;
    return 0;
}