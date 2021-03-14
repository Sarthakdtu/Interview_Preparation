	void turn_off(int n, int r, int c, 
		map<long long, long long>& cell, 
		map<long long, long long>& row, map<long long, long long>& col, 
		map<long long, long long>& d1, map<long long, long long>& d2){

		if(r < 0 || c < 0 || r>=n || c>=n)
			return ;
		long long cell_num = (long long)r*(long long)n + (long long)c;
		if(cell[cell_num] == 0)
			return;

		// cout<<"Switching off"<<r<<" "<<c<<endl;

		cell[cell_num] = 0;
		
		row[r]--;
		col[c]--;
		d1[r - c]--;
		d2[r + c]--;
	}

	class Solution {
	public:
	    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& q) {
	        map<long long, long long> cell;
	        map<long long, long long> row;
	        map<long long, long long> col;
	        map<long long, long long> d1;
	        map<long long, long long> d2;
	        vector<int> ans;
	        for(int i=0;i<lamps.size();i++){
	        	long long r = lamps[i][0];
	        	long long c = lamps[i][1];
	        	long long cell_num = (long long)r*(long long)n + (long long)c;
	        	if(cell[cell_num] == 1)
	        		continue;
	        	cell[cell_num] = 1;
	        	row[r]++;
	        	col[c]++;
	        	d1[r-c]++;
	        	d2[r+c]++;
	        }

	        for(int i=0;i<q.size();i++){
	        	int r = q[i][0];
	        	int c = q[i][1];
	        	int a = 0;
	        	long long cell_num = (long long)r*(long long)n + (long long)c;
	        	if(row[r] > 0){
	        		// cout<<"Case 1"<<r<<endl;
	        		a = 1;
	        		// cout<<row[r]<<endl;
	        	}
	        	else if(col[c] > 0){
	        		// cout<<"Case 2"<<c<<endl;
	        		a = 1;
	        		// cout<<col[c]<<endl;
	        	}
	        	else if(cell[cell_num] == 1){
	        		// cout<<"Case 3"<<r<<c<<endl;
	        		a = 1;
	        		// cout<<cell[cell_num]<<endl;
	        	}
	        	else if(d1[r - c] > 0){
	        		// cout<<"Case 4"<<r-c<<endl;
	        		a = 1;
	        		// cout<<d1[r-c]<<endl;
	        	}
	        	else if(d2[r + c] > 0){
	        		// cout<<"Case 5"<<r+c<<endl;
	        		a = 1;
	        		// cout<<d2[r+c]<<endl;
	        	}

	        	//turn off adj lamps
	        	turn_off(n, r, c, cell, row, col, d1, d2);
	        	turn_off(n, r-1, c, cell, row, col, d1, d2);
	        	turn_off(n, r-1, c-1, cell, row, col, d1, d2);
	        	turn_off(n, r, c-1, cell, row, col, d1, d2);
	        	turn_off(n, r+1, c-1, cell, row, col, d1, d2);
	        	turn_off(n, r+1, c, cell, row, col, d1, d2);
	        	turn_off(n, r+1, c+1, cell, row, col, d1, d2);
	        	turn_off(n, r, c+1, cell, row, col, d1, d2);
	        	turn_off(n, r-1, c+1, cell, row, col, d1, d2);
	        	
	        	ans.push_back(a);        		
	        }
	        return ans;
	    }
	}; 