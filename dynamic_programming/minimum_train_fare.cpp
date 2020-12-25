//https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& arr, vector<int>& cost) {
        vector<int> dp(367);
         int n = arr.size();
        dp[366] = 0;
        unordered_map<int, int> pres;
        for(int i = 0;i<n;i++)
            pres[arr[i]] = 1;
       
       
        for(int i=365;i>-1;i--){
            dp[i] = dp[i+1];
            if(pres[i]==1){
               
                dp[i] = min(
                    dp[i+1] + cost[0],
                    min(
                        dp[min(i+7, 366)] + cost[1],
                        dp[min(i+30, 366)] + cost[2]
                    )
                );
                
            }
//             dp[arr[i]] = cost[0] + dp[arr[i+1]];
//             int j;
//             for(j=i+1;j<n;j++)
//                 if(arr[i] + 6 < arr[j])
//                     break;
//             if(j==n)
//                 dp[arr[i]] = min(dp[arr[i]], cost[1]);
//             else
//                 dp[arr[i]] = min(dp[arr[i]], dp[arr[j]] + cost[1]);
            
//             for(j=i+1;j<n;j++)
//                 if(arr[i] + 29 < arr[j])
//                     break;
//             if(j==n)
//                 dp[arr[i]] = min(dp[arr[i]], cost[2]);
//             else
//                 dp[arr[i]] = min(dp[arr[i]], dp[arr[j]] + cost[2]);
        }
        return dp[0];
    }
};