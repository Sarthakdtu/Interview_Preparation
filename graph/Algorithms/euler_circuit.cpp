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

int main(){
	sarthak();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > adj(n);
		int degree[n];
		for(int i=0;i<n;i++){
			adj[i] = vector<int>(n);
			degree[i] = 0;
			for(int j=0;j<n;j++){
				cin>>adj[i][j];
				if(adj[i][j] == 1)
					degree[i]++;
			}
		}

		if(n == 1){
		    cout<<"True"<<endl;
		    continue;
		}

		bool flag = true;
		for(int i=0;i<n;i++){
			if(degree[i] == 0 || degree[i]&1){
				flag = false;
				break;
			}
		}

		if(flag)
			cout<<"True";
		else
			cout<<"False";
		cout<<endl;
	}
    return 0;
}