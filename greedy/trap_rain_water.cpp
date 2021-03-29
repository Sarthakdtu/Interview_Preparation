class Solution {
public:
    int trap(vector<int>& height) {
        //min(lmax[i], rmax[i]) - height[i]
        int n = height.size();
        int left=0, right=n-1, lb=height[0], rb=height[n-1];
        int ans = 0;

        while(left<=right){
        	if(height[left] <= height[right]){
        		if(height[left] >= lb)
        			lb = height[left];
        		else
        			ans += lb - height[left];
        		left++;
        	}
        	else{
        		if(height[right] >= rb)
        			rb = height[right];
        		else
        			ans += rb - height[right];
        		right--; 
        	}
        }
        return ans;
    }
};