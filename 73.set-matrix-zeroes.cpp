/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> zerom;
        vector<int> zeron;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    zerom.push_back(i);
                    zeron.push_back(j);
                }
            }
        }
        for(auto i : zerom){
            for(int j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }
        for(auto j : zeron){
            for(int i = 0; i < m; i++){
                matrix[i][j] = 0;
            }
        }
        return;
    }
};
// @lc code=end

