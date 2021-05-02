class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 1;
    
        	int curr =1;
        	for(int i=0;i<n;i++){
        		if(arr[i] >= curr){
        			ans = curr;
        			curr++;
        		}
        	}

            return ans;
        
    }
};