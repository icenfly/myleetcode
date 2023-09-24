/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        dfs(0,k,0,n,res,1);
        return ans;
    }
    void dfs(int c, int k,int sum, int n, vector<int> res, int start){
        if(c == k && sum == n){
            ans.push_back(res);
        }
        for(int i = start; i <= 9; i++){
            if(i + sum <= n){
                res.push_back(i);
                dfs(c+1,k,i+sum,n,res,i+1);
                res.pop_back();
            }
        }
    }
};
// @lc code=end

