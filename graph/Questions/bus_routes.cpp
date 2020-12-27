//https://leetcode.com/problems/bus-routes/

int bus_routes(vector<vector<int> > routes, int s, int d){
	map<int, vector<int> > bus_num;
	bool vis_stops[1000000];
	bool vis_bus[501];
	int ans = -1;
	memset(vis_stops, false, sizeof(vis_stops));
	memset(vis_bus, false, sizeof(vis_bus));
	queue<pair<int, int> > q;
	int num_buses = -1;
	
	for(int i=0;i<routes.size();i++){
		for(int j=0;j<routes[i].size();j++){
			int bus_stop = routes[i][j];
			bus_num[bus_stop].push_back(i);
		}
	}

	q.push({s, 0});
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop();
		if(curr.first == d){
			ans = curr.second;
			return ans;
		}
		int cost = curr.second;
		int bus_stop = curr.first;
		for(auto bus : bus_num[bus_stop]){
			if(!vis_bus[bus]){
				for(int i=0;i<routes[bus].size();i++){
					int next = routes[bus][i];
					if(!vis_stops[next]){
						q.push( { next, cost + 1 } );
						vis_stops[next] = true;
					}
				}
				vis_bus[bus] = true;
			}
		}
	}
	return ans;
}