/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> line(n,0);
        vector<vector<int>> res(n,line);
        spiral(res,0,0,0,1,n);
        return res;
    }
    void spiral(vector<vector<int>>& res, int i, int j, int cnt, int dir, int n){
        if(cnt >= n*n){
            return;
        }
        if(i >= 0 && i < n && j >= 0 && j < n){
            if(res[i][j] != 0){
                return;
            }
            else{
                res[i][j] = ++cnt;
            }
        }
        else{
            return;
        }
        if(dir == 1){
            if(j >= n-1 || res[i][j+1] != 0){
                spiral(res,i+1,j,cnt,2,n);
            }
            else{
                spiral(res,i,j+1,cnt,1,n);
            }
        }
        if(dir == 2){
            if(i >= n-1 || res[i+1][j] != 0){
                spiral(res,i,j-1,cnt,3,n);
            }
            else{
                spiral(res,i+1,j,cnt,2,n);
            }
        }
        if(dir == 3){
            if(j <= 0 || res[i][j-1] != 0){
                spiral(res,i-1,j,cnt,4,n);
            }
            else{
                spiral(res,i,j-1,cnt,3,n);
            }
        }
        if(dir == 4){
            if(i <= 0 || res[i-1][j] != 0){
                spiral(res,i,j+1,cnt,1,n);
            }
            else{
                spiral(res,i-1,j,cnt,4,n);
            }
        }
    }
};
// @lc code=end

