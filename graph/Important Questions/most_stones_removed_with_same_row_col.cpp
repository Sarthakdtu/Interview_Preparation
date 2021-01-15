//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/submissions/

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
	int find(int x){
		if(x == parent[x])
			return x;
        parent[x] = find(parent[x]);
		return parent[x];
	}

	void merge(int r, int c, int &count){
		int pr = find(r);
		int pc = find(c);
		if(pr!=pc){
			count--;
			if(rank[pr] > rank[pc])
				parent[pc] = pr;
			else if(rank[pc] > rank[pr])
				parent[pr] = pc;
			else{
				parent[pc] = pr;
				rank[pr]++;
			}
		}
	}

    int removeStones(vector<vector<int>>& arr) {
       
        int r, c;
        int count = 0;

        for(int i=0;i<arr.size();i++){
        	r = arr[i][0]+1;
        	c = -(arr[i][1]+1);
        	if(parent[r] == 0){
        		count++;
        		parent[r] = r;
        	}
        	if(parent[c] == 0){
        		count++;
        		parent[c] = c;
        	}
        	merge(r, c, count);
        }
        return arr.size()-count;
    }
};