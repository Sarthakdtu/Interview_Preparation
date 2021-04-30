class Solution {
public:
    vector<int> findAnagrams(string s, string p){
    	map<char, int> f;
    	vector<int> ans;
    	int ps = p.size();
    	int match = 0;
    	map<char, int> m;
    	int i;
    	for(i=0;i<ps;i++)
    		f[p[i]]++;
    	for(i=0;i<ps;i++){
    		m[s[i]]++;
    		if(f[s[i]] !=0 && m[s[i]] <= f[s[i]])
    			match++;
    	}
    	if(match == ps)
    		ans.push_back(0);
    	int j = ps-1;
    	i = 0;
    	while(j<s.size()-1){
           // cout<<"match "<<match<<endl;
    		if(f[s[i]] > 0 && m[s[i]] <= f[s[i]])
    			match--;
    		m[s[i]]--;
            
    		i++;
    		j++;
    		m[s[j]]++;
           //cout<<"add "<<s[j]<<endl;
    		if(f[s[j]] !=0 && m[s[j]] <= f[s[j]])
    			match++;
    		if(match == ps)
    			ans.push_back(i);
    	}
    	return ans;
    }
};