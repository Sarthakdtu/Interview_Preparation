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
    int v, e;
    cin>>v>>e;
    vector<pair<ll, ll> > graph[v];
    for(int i=0;i<e;i++){
        ll s, d, c;
        cin>>s>>d>>c;
        s--;d--;
        graph[s].push_back({c, d});
        graph[d].push_back({c, s});
    }

    ll mst = 0;
    bool vis[v];
    memset(vis, false, sizeof(vis));
    set<pair<ll, ll> > pq;
    int count = 0;
    int source = 0;

    pq.insert({source, 0});
    
    while(count!=v){
        auto curr = *(pq.begin());
        pq.erase(pq.begin());
        source = curr.second;
        if(!vis[source]){
            for(auto u: graph[source]){
                pq.insert(u);
            }
            vis[source] = true;
            count++;
            mst += curr.first;
        }
    }
    cout<<mst<<endl;

    return 0;
}