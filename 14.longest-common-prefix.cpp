/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int min = 400;
        for(int i = 0 ; i <= strs.size()-1;i++){
            if(strs[i].size()<min) min = strs[i].size();
        }
        for(int i = 0; i<= min-1;i++){
            bool flag = true;
            for(int j = 0 ; j <= strs.size()-1;j++){
            if(strs[j][i]!=strs[0][i]) flag = false;
            }
            if(flag){
                ans += strs[0][i];
            } 
            else{
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

