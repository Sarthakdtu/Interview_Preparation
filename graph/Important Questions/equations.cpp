//https://leetcode.com/problems/evaluate-division/

void dfs(string source, map<string, vector<string> > &nbrs, map<string, int> &comps, int comp,  map<string, int> &vis, map<string, double> &calc, map<string, map<string, double> > &ratio){
    // cout<<source<<endl;
	comps[source] = comp;
	vis[source] = 1;
	for(auto v: nbrs[source]){
		if(vis[v] == 0){
            calc[v] = ratio[v][source] * calc[source];
			dfs(v, nbrs, comps, comp, vis, calc, ratio);
			
            // cout<<ratio[v][source]<<" "<<calc[source]<<" "<<calc[v]<<endl;
		}
	}
}

vector<double> calcEquation(vector<vector<string> > eqs, vector<double> &vals, vector<vector<string> > &queries){
	map<string, vector<string> > nbrs;
	map<string, int> comps;
	map<string, int> vis;
	map<string, double> calc;
    map<string, map<string, double> > ratio;
	for(int i=0;i<eqs.size();i++){
		string a = eqs[i][0];
		string b = eqs[i][1];
		nbrs[a].push_back(b);
		nbrs[b].push_back(a);
		ratio[a][b] = vals[i];
		ratio[b][a] = 1.0/vals[i];
	}

	int comp = 1;
	for(auto v: nbrs){
		if(vis[v.first]==0){
			calc[v.first] = 1.0;
            // cout<<v.first<<" "<<calc[v.first]<<endl;
			dfs(v.first, nbrs, comps, comp, vis, calc, ratio);
			comp++;
		}
	}


	vector<double> ans;
	for(int i=0;i<queries.size();i++){
		string a = queries[i][0];
		string b = queries[i][1];
        // cout<<calc[a]<<" "<<calc[b]<<endl;
        
		if(comps[a]==0 || comps[b]==0 || comps[a] != comps[b]){
			ans.push_back(-1.0);
		}
		else{
			ans.push_back( calc[a]/calc[b] );
		}
	}
	return ans;
}