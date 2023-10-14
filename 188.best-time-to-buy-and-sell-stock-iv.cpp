/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int max_k = k;
        int n = prices.size();
        if(max_k > n/2){
            int dp[n][2];
            for(int i = 0; i <= n-1; i++){
                if(i == 0){
                    dp[i][0] = 0;
                    dp[i][1] = -prices[i];
                    continue;
                }
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            }
            return dp[n-1][0];     
        }
        else{
            int dp[n][max_k+1][2];
            for (int i = 0; i <= n-1; i++) {
                dp[i][0][0] = 0;
                dp[i][0][1] = INT_MIN;
            } 
            for(int i = 0; i <= n-1; i++){
                for(int k = max_k; k >= 1; k--){
                    if(i == 0){
                        dp[i][k][0] = 0;
                        dp[i][k][1] = -prices[i];
                        continue;
                    }
                    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
                }
            }
            return dp[n-1][max_k][0];     
        }
        return 0;
    }
};
// @lc code=end

