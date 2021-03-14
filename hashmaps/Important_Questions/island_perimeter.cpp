//https://leetcode.com/problems/island-perimeter/

int func(vector<vector<int>>& arr, int i, int j){
	int n = arr.size();
    int m = arr[0].size();

	if( i < 0 || j<0 || i>=n || j>=m || arr[i][j] == 0)
		return 1;
	return 0;
}


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& arr){
    	int n = arr.size();
    	int m = arr[0].size();
        
        int peri = 0;
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(arr[i][j] == 1){
        			peri += func(arr, i-1, j);
        			peri += func(arr, i, j-1);
        			peri += func(arr, i, j+1);
        			peri += func(arr, i+1, j);
        		}
        	}
        }
        return peri;
    }
};