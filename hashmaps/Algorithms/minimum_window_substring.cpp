class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> ft;
        int ts = t.size();
        for(int i=0;i<ts;i++)
        	ft[t[i]]++;
        int match = 0;
        map<char, int> fs;
        int i=0, j=0;
        int ml = 0, si = 0;
        while(i<s.size()){
        	//expand window
        	while(j<s.size() && match < ts){
        		fs[s[j]]++;
        		if(ft[s[j]] >0 && fs[s[j]] <= ft[s[j]])
        			match++;
        		j++;
        	}
        	if(match == ts){
        		int len = j-i;
        		if(ml > len){
        			si = i;
        			ml = len;
        		}
        	}
        	//compress window
        	while(i<j && match == ts){
        		if(ft[s[i]] > 0 && fs[s[i]] <= ft[s[i]])
        			match--;
        		fs[s[i]]--;
        		i++;
        	}

        	if(match == ts){
        		int len = j-i;
        		if(ml > len){
        			si = i;
        			ml = len;
        		}
        	}


        	if(j==s.size())
        		break;
        }
        string ans = "";
        if(ml==0)
        	return ans;
        for(int i=si;i<si+ml;i++)
        	ans += s[i];

        return ans;
    }
};