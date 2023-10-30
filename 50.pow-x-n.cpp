/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0){
            return 0.0;
        }
        if(x == 1){
            return 1.0;
        }
        if(x == -1){
            if(n%2 == 0){
                return 1.0;
            }
            else{
                return -1.0;
            }
        }
        if(n == 0){
            return 1.0;
        }
        if(n > 0){
            double ans = 1;
            while(n != 0){
                if(n & 1 != 0){
                    ans *= x;
                }
                x *= x;
                n = n>>1;
            }
            return ans;
        }
        if(n < 0){
            double ans = 1;
            long long n1 = 0;
            if(n == -2147483648){
                n1 = 2147483648;
            }
            else{
                n1 = -n;
            }
            while(n1 != 0){
                if(n1 & 1 != 0){
                    ans = (1.0)*ans/x;
                }
                x *= x;
                n1 = n1>>1;
            }
            return ans;
        }
        return 0.0;
    }
};
// @lc code=end

