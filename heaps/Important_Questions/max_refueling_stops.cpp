//https://leetcode.com/problems/minimum-number-of-refueling-stops/

//https://leetcode.com/problems/minimum-number-of-refueling-stops/


class Solution {
public:
    int minRefuelStops(int dest, int start, vector<vector<int>>& stns) {
        priority_queue<int> pq;
        int count = 0;
        int pos = start;
        int idx = 0;
        while(pos < dest){
        	for(int i=idx;i<stns.size() && pos >= stns[i][0];i++){
        		if(pos < stns[i][0])
        			break;
        		pq.push(stns[i][1]);
        		idx++;
        	}
        	if(pq.size() == 0){
        		return -1;
        	}
        	pos += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};