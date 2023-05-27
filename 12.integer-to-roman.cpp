/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        while(num >=1000){
            num -= 1000;
            ans = ans + "M";
        }
        while(num >=900){
            num -= 900;
            ans = ans + "CM";
        }
        while(num >=500){
            num -= 500;
            ans = ans + "D";
        }
        while(num >=400){
            num -= 400;
            ans = ans + "CD";
        }
        while(num >=100){
            num -= 100;
            ans = ans + "C";
        }
        while(num >=90){
            num -= 90;
            ans = ans + "XC";
        }
        while(num >=50){
            num -= 50;
            ans = ans + "L";
        }
        while(num >=40){
            num -= 40;
            ans = ans + "XL";
        }
        while(num >=10){
            num -= 10;
            ans = ans + "X";
        }
        while(num >=9){
            num -= 9;
            ans = ans + "IX";
        }
        while(num >=5){
            num -= 5;
            ans = ans + "V";
        }
        while(num >=4){
            num -= 4;
            ans = ans + "IV";
        }
        while(num >=1){
            num -= 1;
            ans = ans + "I";
        }
        return ans;
    }
};
// @lc code=end

