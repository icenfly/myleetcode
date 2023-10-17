/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            ans = say(ans);
        }   
        return ans;
    }
    string say(string ans){
        string res = "";
        char k = 'a';
        int count = 0;
        for(int i = 0; i <= ans.size()-1; i++){
            if(k != ans[i]){
                if(k != 'a' && count != 0){
                    res += char(int('0')+count);
                    res += k;
                }
                k = ans[i];
                count = 1;
            }
            else{
                count ++;
            }
        }
        res += char(int('0')+count);
        res += k;   
        return res;
    }
};
// @lc code=end

