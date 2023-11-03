/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;    
        spiral(0,0,1,matrix,ans);
        return ans;
    }
    void spiral(int i, int j, int prev, vector<vector<int>>& matrix, vector<int>& ans){
        int m = matrix.size();
        int n = matrix[0].size();
        if(i >= 0 && i < m && j >= 0 && j < n){
            if(matrix[i][j] == -200){
                return;
            }
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -200;
        }
        else{
            return;
        }
        if(prev == 1){
            if(j+1 >= n || matrix[i][j+1] == -200){
                spiral(i+1,j,2,matrix,ans);
            }
            else{
                spiral(i,j+1,1,matrix,ans);
            }
        }
        if(prev == 2){
            if(i+1 >= m || matrix[i+1][j] == -200){
                spiral(i,j-1,3,matrix,ans);
            }
            else{
                spiral(i+1,j,2,matrix,ans);
            }
        }
        if(prev == 3){
            if(j <= 0 || matrix[i][j-1] == -200){
                spiral(i-1,j,4,matrix,ans);
            }
            else{
                spiral(i,j-1,3,matrix,ans);
            }
        }
        if(prev == 4){
            if(i <= 0 || matrix[i-1][j] == -200){
                spiral(i,j+1,1,matrix,ans);
            }
            else{
                spiral(i-1,j,4,matrix,ans);
            }
        }
    }
};
// @lc code=end

