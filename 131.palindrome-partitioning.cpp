/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subres;
        papa(s, 0, subres, res);
        return res;
    }
    void papa(string &s, int index, vector<string> &subres, vector<vector<string>> &res){
        if(index >= s.size()){
            res.push_back(subres);
            return;
        }
        for(int i = index; i <= s.size()-1; i++){
            if(isPalindrome(s,index,i)){
                subres.push_back(s.substr(index, i-index+1));
                papa(s, i+1, subres, res);
                subres.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int begin, int end){
        int i = begin;
        int j = end;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i ++;
            j --;
        }
        return true;
    }
};
// @lc code=end

