/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        long long ans[50] = {0,1,2};
        if(n==1) return 1;
        if(n==2) return 2;
        for(int i = 3 ; i <= n;i++){
            ans[i] = ans[i-1]+ans[i-2];
        }
        return ans[n];
    }
};
// @lc code=end

