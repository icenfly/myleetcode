/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<int> line(n+1,0);
        vector<vector<int>> dp(m+1,line);
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 && j == 1){
                    dp[i][j] = 1;
                    continue;
                } 
                if(i == 1){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j == 1){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                if(obstacleGrid[i-1][j-1] == 1){
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

