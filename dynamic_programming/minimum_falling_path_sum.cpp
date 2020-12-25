//https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int dp[n][n];
        memset(dp, INT_MAX, sizeof(dp));
        for(int i=0;i<n;i++){
            dp[n-1][i] = arr[n-1][i];
        }
        
        for(int i=n-2;i>-1;i--){
            for(int j=0;j<n;j++){
                dp[i][j] = dp[i+1][j];
                if(j - 1 > -1)
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                if(j + 1 < n)
                    dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
                dp[i][j] += arr[i][j]; 
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};