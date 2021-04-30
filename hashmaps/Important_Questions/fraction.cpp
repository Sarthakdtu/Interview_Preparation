
class Solution{
	public:
	string fractionToDecimal(int n, int d) {
		string ans = "";
	    int q, r, idx=0, prev=n;
	    bool dec = false;
	    map<int, int> vis;
	    while(n > 0){
	    	if(n<d){
	    		n = n*10;
	    		//dec = true;
	    		if(idx == 0){
	    			ans += "0";
	    			idx++;
	    		}
	    	    if(!dec){
	    	    	ans += ".";
	    			dec = true;
	    			idx++;
	    	    }
	    	}
	    	q = n/d;
	    		n = n - (d*q);
	    	string sq = to_string(q);
	    	//cout<<"Adding "<<sq<<endl;
	    //	cout<<"gidx ="<<idx<<endl;
	    	if(dec){
	    	    //cout<<ans;
	    		if(vis[prev] == 0){
	    			vis[prev] = idx;
	    			//cout<<"Adding "<<sq<<" at "<<idx<<endl;
	    			ans += sq;
	    			//cout<<ans;
	    			idx = ans.size();
	    		//	cout<<"new idx = "<<idx<<endl;
	    		}
	    		else{
	    			idx = vis[prev];
	    		//	ans += sq;
	    		//cout<<"idx at "<<idx<<endl;
	    			ans = ans.substr(0, idx) + "(" + ans.substr(idx, ans.size()) + ")";
	    			break;
	    		}
	    	}
	    	else{
	    		//cout<<"?";
	    		ans += sq;
	    		idx += sq.size();
	    	}
	    	prev = n;
	    } 
	    return ans;
	}
};
