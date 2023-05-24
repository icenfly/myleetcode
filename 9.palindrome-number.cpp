/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        if(x%10==0) return false;
        long long y = 0;
        while(x>0){
            y += x%10;
            if(x==y) return true;
            x = x/10;
            if(x==y) return true;
            y = y*10;
        }
        return false;
    }
};
// @lc code=end

