class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
  		priority_queue<int, vector<int>, greater<int> > pq;
  		int n = arr.size();
  		for(int i=0;i<k;i++)
  			pq.push(arr[i]);
  		for(int i=k;i<n;i++){
  			int top = pq.top();
  			if( top < arr[i]){
  				pq.pop();
  				pq.push(arr[i]);
  			}
  		}
  		return pq.top();
    }
};