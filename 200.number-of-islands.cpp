/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        int a[5] = {0,0,0,1,-1};
        int b[5] = {0,1,-1,0,0};
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '0';
        for(int k = 1; k<=4;k++){
            if((i+a[k]>=0)&&(i+a[k]<m)&&(j+b[k]>=0)&&(j+b[k]<n)&&grid[i+a[k]][j+b[k]]=='1'){
                dfs(grid,i+a[k],j+b[k]);
            }
        }
    }
};
// @lc code=end

