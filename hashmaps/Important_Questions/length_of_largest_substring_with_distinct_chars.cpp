class Solution{
    public:
    int longestUniqueSubsttr(string str){
    	map<char, int> arr;
    	int si = 1, len = 0, curr=0, i=0, j=0, n = str.size();


		while(j<n){
			int idx = arr[str[j]];
			if( idx== 0 || idx<si){
				//acceptable
				curr++;
			}
			else{
				//reject
				if(len <curr)
					len = curr;
				si = idx+1;
				curr = j - (si-1) + 1;
			}
			arr[str[j]] = j+1;
			j++;
		}
		if(len <curr)
			len = curr;
		return len;
	}
    
};