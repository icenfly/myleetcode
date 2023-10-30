/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1){
            return;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
        return;
    }
};
// @lc code=end

