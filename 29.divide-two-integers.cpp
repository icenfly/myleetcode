/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        long long dvd = llabs(dividend);
        long long dvs = llabs(divisor);
        long long ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1:1;
        while(dvd >= dvs){
            long long temp = dvs;
            long long m =1 ;
            while(temp << 1 <= dvd){
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign*ans;
    }
};
// @lc code=end

