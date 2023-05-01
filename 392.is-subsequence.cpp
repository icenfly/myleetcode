/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i = 0; i < t.size(); i++){
            if(j==s.size()) return true;
            if(t[i]==s[j]){
                j++;
            }
        }
        if(j==s.size()) return true;
        return false;
    }
};
// @lc code=end

