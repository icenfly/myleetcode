/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int y = x;
        int z = 0;
        int k;
        bool flag = false;
        if(y==-2147483648){
            return 0;
        }
        if(y>0){
            while(y > 0){
                if(flag&&(y%10)>7){
                    return 0;
                }
                z += y%10;
                y = y/10;
                if(z>214748364&&y>0){
                    return 0;
                }
                if(z==214748364){
                    flag = true;
                }
                if(y>0){
                    z = z*10;
                }
            }
            return z;
        }
        else if(y==0){
            return 0;
        }
        else if(y<0){
            y = -y;
            while(y > 0){
                if(flag&&(y%10)>8){
                    return 0;
                }
                z += y%10;
                y = y/10;
                if(z>214748364&&y>0){
                    return 0;
                }
                if(z==214748364){
                    flag = true;
                }
                if(y>0){
                    z = z*10;
                }
            }
            return z*(-1);
        }
        return 0;
    }
};
// @lc code=end

