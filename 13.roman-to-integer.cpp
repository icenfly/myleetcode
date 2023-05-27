/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int ans = 0;
        while(i<=s.size()-1){
            if(s[i]=='M'){
                ans+=1000;
            }
            if(s[i]=='D'){
                ans+=500;
            }
            if(s[i]=='C'){
                if(i+1<=s.size()-1&&(s[i+1]=='D'||s[i+1]=='M')){
                    ans-=100;
                }
                else{
                    ans+=100;
                }
            }
            if(s[i]=='L'){
                ans+=50;
            }
            if(s[i]=='X'){
                if(i+1<=s.size()-1&&(s[i+1]=='L'||s[i+1]=='C')){
                    ans-=10;
                }
                else{
                    ans+=10;
                }
            }
            if(s[i]=='V'){
                ans+=5;
            }
            if(s[i]=='I'){
                if(i+1<=s.size()-1&&(s[i+1]=='V'||s[i+1]=='X')){
                    ans-=1;
                }
                else{
                    ans+=1;
                }
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

