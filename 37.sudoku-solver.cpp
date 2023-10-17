/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solvedfs(board,0,0);
    }
    bool solvedfs(vector<vector<char>>& board,int i, int j){
        if(i == 9){
            return true;
        }
        if(j == 9){
            return solvedfs(board,i+1,0);
        }
        if(board[i][j] != '.'){
            return solvedfs(board,i,j+1);
            //thats how you continue in dfs
        }
        for(int k = 1; k <= 9; k++){
            if(test(board,i,j,char(int('0')+k))){
                board[i][j] = char(int('0')+k);
                if(solvedfs(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    bool test(vector<vector<char>>& board,int i, int j, char k){
        for(int x = 0; x <= 8; x++){
            if(board[x][j] == k){
                return false;
            }
        }
        for(int y = 0; y <= 8; y++){
            if(board[i][y] == k){
                return false;
            }
        }
        int x1 = i - i%3;
        int y1 = j - j%3;
        for(int x = 0; x <= 2; x++){
            for(int y = 0; y <= 2; y++){
                if(board[x+x1][y+y1] == k){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

