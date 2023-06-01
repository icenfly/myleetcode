/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        const vector<string> chars = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        backtracking(digits,"",ans,chars);
        return ans;
    }
    void backtracking(string digits,string sum,vector<string>& ans,const vector<string> chars){
        if(digits.size()==0){
            ans.push_back(sum);
            return;
        }
        for(int i = 0; i <= chars[int(digits[0])-int('0')].size()-1;i++){
            backtracking(digits.substr(1),sum+chars[int(digits[0])-int('0')][i],ans,chars);
        }
    }
};
// @lc code=end

