class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<float , int> m;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        	m[arr[i]]++;

        float num;
        for(int i=0;i<n;i++){
        	if(m[arr[i]] == 0)
        		continue;
        	if(arr[i]>=0)
        		num = 2*arr[i];
        	else
        		num = float(arr[i])/2.0;
        	m[arr[i]]--;
        	if(m[num]>0)
        		m[num]--;
        	else
        		return false;
        }
        return true;

    }
};