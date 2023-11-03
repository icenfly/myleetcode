/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 1){
            return 1;
        }
        
        if(s[s.size()-1] != ' '){
            for(int i = s.size()-1; i >= 0; i--){
                if(s[i] == ' '){
                    return s.size()-1-i;
                }
            }
            return s.size();
        }
        
        if(s[s.size()-1] == ' '){
            int i;
            for(i = s.size()-1; i >= 0; i--){
                if(s[i] != ' '){
                    break;
                }
            }
            int j = i;
            for(;i >=0;i--){
                if(s[i] == ' '){
                    return j-i;
                }
            }
            return j+1;
        }
        return 1;
    }
};
// @lc code=end

