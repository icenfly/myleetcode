/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int in_ans =0;
        int leng_ans =0;
        for(int in = 0; in <= s.size()-1;in++){
            for(int leng = leng_ans+1; leng+in <= s.size(); leng++){
                isP(s,in,leng,in_ans,leng_ans);
            }
        }
        return s.substr(in_ans,leng_ans);
    }
    void isP(const string &s, int in, int leng, int &in_ans, int &leng_ans){
        bool flag = true;
        for(int i = 1; i <= leng/2; i++){
            if(s[in+i-1]!=s[in+leng-i]){
                flag = false;
                break;
            }
        }
        if(flag){
            in_ans = in;
            leng_ans = leng;
        }
    }
};
// @lc code=end

