class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
    	int n = arr.size();
    	int count = 0;
    	vector<int> pre(n);
    	unordered_map<int, int> occ;
    	pre[0] = arr[0];
    	for(int i=1;i<n;i++)
    		pre[i] = pre[i-1] + arr[i];

    	occ[0] = 1;
    	for(int j=0;j<n;j++){
    		int diff = pre[j] - k;
    		count += occ[diff];
    		occ[pre[j]]++;
    	}
    	return count;
    }
};