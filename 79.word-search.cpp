/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(word.size() > m*n){
            return false;
        }
        for(int i = 0; i <= word.size()-2;i++){
            if(word[i] != word[i+1]){
                if(i*2 > word.size()){
                    reverse(word.begin(), word.end()); 
                    break;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,int x, int y, string word, int index){
        int m = board.size();
        int n = board[0].size();
        vector<int> changei{-1,1,0,0}; 
        vector<int> changej{0,0,1,-1};
        if(index >= word.size()){
            return true;
        }
        if(!(x >= 0 && y >= 0 && x < m && y < n)){
            return false;
        }
        if(board[x][y] != word[index]){
            return false;
        }
        char newword = board[x][y];
        board[x][y] = '*';
        bool flag = dfs(board,x+1,y,word,index+1)||dfs(board,x-1,y,word,index+1)||dfs(board,x,y+1,word,index+1)||dfs(board,x,y-1,word,index+1);
        board[x][y] = newword;
        return flag;
    }
};
// @lc code=end

