

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> m;
        int wall_sum = 0;
        int n = wall.size();
        for(int i=0;i<n;i++){
        	int sum = 0;
        	for(int j=0;j<wall[i].size();j++){
        		sum += wall[i][j];
        		m[sum]++;
        	}
        	wall_sum = sum;
        }
        int max_len = 0;
        for(auto itr=m.begin();itr!=m.end();itr++){
        	if(itr->first == wall_sum)
        		continue;
        	max_len = max(max_len, itr->second);
        }
        return n - max_len;
    }
};