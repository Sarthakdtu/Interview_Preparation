class Solution{

	public:
	long long subCount(long long arr[], int n, long long k){
		long long pre[n];
		pre[0] = arr[0];
		int count = 0;
		unordered_map<int, int> occ;
	    
	    for(int i=1;i<n;i++)
	    	pre[i] = pre[i-1] + arr[i];
	    for(int i=0;i<n;i++){
	    	pre[i] = pre[i] % k;
	    	if(pre[i] < 0)
	    		pre[i] += k;
	    }

	    occ[0] = 1;
	    for(int j=0;j<n;j++){
	    	count += occ[pre[j]];
	    	occ[pre[j]]++;
	    }
	    return count;
	}



};