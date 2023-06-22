/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("",ans,n,0);
        return ans;
    }
    void dfs(string t, vector<string> &ans,int n,int m){
        if(n==0&&m==0){
            ans.push_back(t);
            return;
        }
        if(m>0){
            dfs(t+")",ans,n,m-1);
        }
        if(n>0){
            dfs(t+"(",ans,n-1,m+1);
        }
    }
};
// @lc code=end

