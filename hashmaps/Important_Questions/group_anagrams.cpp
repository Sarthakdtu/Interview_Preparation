class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	int arr[26] = {0};
    	string temp;
    	map<string, vector<string> > res;
    	vector<vector<string> > ans;
    	for(int i=0;i<strs.size();i++){
    		arr[26] = {0};
    		for(int j=0;j<strs[i].size();j++)
    			arr[strs[i][j] - 'a']++;
    		temp = "";
    		for(int k=0;k<26;k++)
    			temp = temp + to_string(arr[k]) + "_";
    		res[temp].push_back(strs[i]); 
    	}

    	for(auto itr=res.begin();itr!=res.end();itr++)
    		ans.push_back(itr->second);

    	return ans;
    }
};