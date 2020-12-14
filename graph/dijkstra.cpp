#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
        //freopen("error.txt", "w", stderr);
	#endif
}
 
int main()
{
    sarthak();
    int t;
    cin>>t;
    while(t--){
    	int v,e;
    	cin>>v>>e;
    	int s, d, c;
    	vector<pair<ll, int > > adj[v];
    	for(int i=0;i<e;i++){
    		
    		cin>>s>>d>>c;
    		s--;
    		d--;
    		adj[s].push_back({c, d});
    	}
    	cin>>s;
    	cin>>d;
    	s--;
    	d--;

    	set<pair<int, int> > pq;
    	int count = 0;
    	bool vis[v];
    	int dist[v];
    	memset(dist, 100000, sizeof(dist));
    	memset(vis, false, sizeof(vis));
    	bool ans = true;

        dist[s] = 0;
        pq.insert({0, s});

    	while(count!=v){
    		pair<int, int> p = *(pq.begin());
    		pq.erase(pq.begin());
    		int u = p.second;
    		int cost_u = p.first;

    		if(!vis[u]){
    			dist[u] = cost_u;
    			vis[u] = true;
    			count++;
    			for(int i = 0;i<adj[u].size();i++){
    				int v = adj[u][i].second;
    				int dist_uv = adj[u][i].first;

    				if(!vis[v]){
    					p.first = cost_u + dist_uv;
    					p.second = v; 
    					pq.insert(p);
    				}
    			}
    		}
    		if(pq.size()==0 && count != v){
    			ans = false;
    			cout<<"NO"<<endl;
    			break;
    		}
    	}   	

    	if(ans)
    		cout<<dist[d]<<endl;
    }

    return 0;
}