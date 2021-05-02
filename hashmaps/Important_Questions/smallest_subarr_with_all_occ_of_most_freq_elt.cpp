
class Solution{
    public:
    vector<int> smallestSubsegment(int arr[], int n){
    	// Complete the function
    	vector<int> ans;
    	int num, max_num=arr[0], f = 0, si, min_len;
    	map<int, vector<int> > m;
    	for(int i=0;i<n;i++){
    		num = arr[i];
    		if(m.find(num) != m.end()){
    			m[num][0]++;
    			m[num][2] = i;
    		}
    		else{
    			m[num] = {1, i, i};
    		}
    		bool update = false;
    		if(f<m[num][0]){
    			min_len = m[num][2] - m[num][1] + 1;
    			f = m[num][0];
    			max_num = num;
    			si = m[num][1];
    		}
    		else if(f == m[num][0]){
    			int len = m[num][2] - m[num][1] + 1;
    			if(min_len > len){
    				min_len = len;
	    			f = m[num][0];
	    			max_num = num;
	    			si = m[num][1];
    			}
    			else if(min_len == len && si>m[num][1]){
    				min_len = len;
	    			f = m[num][0];
	    			max_num = num;
	    			si = m[num][1];
    			}
    		}
    	}
    	num = max_num;
    	for(int i=m[num][1];i<=m[num][2];i++)
    		ans.push_back(arr[i]);
    	return ans;
    }
};