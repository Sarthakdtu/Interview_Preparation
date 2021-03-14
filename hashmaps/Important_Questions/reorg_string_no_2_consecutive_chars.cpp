//https://leetcode.com/problems/reorganize-string/submissions/
class Solution {
public:
    string reorganizeString(string str){
    	int n = str.size();
        map<char, int> freq;
      	for(int i=0;i<n;i++)
      		freq[str[i]]++;
      	priority_queue< pair<int, char> > pq;
		pair<int, char> temp = {0, 'a'};

		int en = n;
		if(n&1)
			en++;
		for(auto itr=freq.begin();itr!=freq.end();itr++){
			pair<int, char> curr = *itr;
			if(curr.second > en/2)
				return "";
			pq.push(curr);
		}

		int len = 0;
		string ans = "";
		while(len < n){
			pair<int, char> curr = pq.top();
			char ch = curr.second;
			ans += ch;
			if(temp.first > 0){
				pq.push({temp.first-1, temp.second});
			}
			temp = curr;
			len++;
		}
		return str;
    }
};