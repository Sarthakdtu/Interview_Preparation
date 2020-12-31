//https://www.hackerrank.com/challenges/torque-and-development/problem
long roadsAndLibraries(int v, int lib, int road, vector<vector<int>> edges) {
	vector<vector<pair<int, int> > >graph(v+1);
	bool *vis = new bool[v+1]();
	set<pair<int, int> > pq;

	for(int i=0;i<=v;i++){
		graph[0].push_back({lib, i});
		graph[i].push_back({lib, 0});
		if(i!=0)
			pq.insert({lib, i});
	}

	for(int i=0;i<edges.size();i++){
		int s = edges[i][0];
		int d = edges[i][1];
		graph[s].push_back({road, d});
		graph[d].push_back({road, s});
	}

	int count = 0;
	int ans = 0;
	while(count!=v){
		pair<int, int> curr = *(pq.begin());
		pq.erase(pq.begin());
		if(!vis[curr.second]){
			for(auto i : graph[curr.second]){
				if(!vis[i.second])
					pq.insert(i);
			}
			count++;
			ans += curr.first;
			vis[curr.second] = true;
		}
	}
	return ans;
}