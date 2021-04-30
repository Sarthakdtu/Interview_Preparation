class Solution{
public:	
	bool sameFreq(string s){
		int n = s.size();
		map<char, int> freq;

		for(int i=0;i<n;i++)
			freq[s[i]]++;
		int prev = 0;
		int cb = -1;
		bool poss = true;
		vector<int> arr;
		for(auto itr=freq.begin();itr!=freq.end();itr++){
			if(arr.size() > 2){
				poss = false;
				break;
			}
			bool exist = false;
			for(int i=0;i<arr.size();i++){
				if(arr[i] == itr->second){
					exist = true;
					break;
				}
			}
			if(!exist){
				arr.push_back(itr->second);
			}
		}
        if(arr.size() == 1)
            return true;
		if(!poss)
			return false;
		else{
			if(arr[0] == 1 ||arr[1] == 1 || arr[0] == arr[1])
				return true;
			else if(arr[0] + 1 == arr[1] || arr[0]-1 == arr[1])
				return true;
			return false;
		}

	}
};