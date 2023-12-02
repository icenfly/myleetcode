/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> cando(s.size()+1, false);
        cando[0] = true;
        for(int i = 0; i <= s.size(); i++){
            if(cando[i]){
                for(int j = i+1; j <= s.size(); j++){
                    if(wordDicthave(s.substr(i,j-i), wordDict)){
                        cando[j] = true;
                    }
                }
            }
        }
        return cando[s.size()];
    }
    bool wordDicthave(string s, vector<string>& wordDict){
        auto it = find(wordDict.begin(), wordDict.end(), s);
        if(it != wordDict.end()){
            return true;
        }
        else{
            return false;
        }
    }
};
// @lc code=end

