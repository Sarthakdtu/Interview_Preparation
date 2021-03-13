class Solution {
public:

	int distance(vector<int> point){
		return (point[0]*point[0]) + (point[1]*point[1]);
	}
    vector<vector<int> > kClosest(vector<vector<int>>& arr, int k) {
    	priority_queue< pair<int, int> > pq;
    	int n = arr.size();
    	vector<vector<int> > ans;
    	for(int i=0;i<k;i++){
    		pq.push( { distance( arr[i] ), i } );
    	}
    	for(int i=k;i<n;i++){
    		pair<int, int> top = pq.top();
    		pair<int, int> curr = { distance( arr[i] ), i };
    		if(top.first >  curr.first){
    			pq.pop();
    			pq.push(curr);
    		}  
    	}
    	for(int i=0;i<k;i++){
    		pair<int, int> top = pq.top();
    		pq.pop();
    		int idx = top.second;
    		ans.push_back(arr[idx]);
    	}
    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};