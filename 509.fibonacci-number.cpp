/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        long long ans1=0;
        long long ans2=1;
        for(int i = 2; i<=n;i++){
            long long temp = ans1;
            ans1 = ans2;
            ans2 = temp+ans2;
        }
        return ans2;
    }
};
// @lc code=end

