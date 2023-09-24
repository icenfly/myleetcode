/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        dfs(n,0,board);
        return ans;
    }

    bool check(vector<string> board, int row, int col){
        for(int i = 0; i <= row-1; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        
        for(int i = row-1, j = col+1; i>=0 && j <= board.size()-1; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row-1, j = col-1; i>=0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        
        return true;
    }   

    void dfs(int n, int queens, vector<string> &board){
        if(queens == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i <= n-1; i++){
            if(check(board, queens, i)){
                board[queens][i] = 'Q';
                dfs(n, queens+1, board);
                board[queens][i] = '.';
            }
        }
    }
};
// @lc code=end

