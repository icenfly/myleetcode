/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
/*
    int myAtoi(string s) {
        int k  = 1;
        int cnt = 0;
        int i;
        if(s.size()==1){
            if(s[i]>='0'&&s[i]<='9') return int(s[i])-int('0');
            else return 0;
        }
        for(i = 0 ; i <= s.size()-1; i++){
            if(s[i]==' ') continue;
            if(s[i]!=' '&&s[i]!='-'&&s[i]!='+'&&(s[i]<'0'||s[i]>'9')){
                return 0;
            }
            if(s[i]=='-'){
                k = -1;
                cnt++;
                if(cnt==2) return 0;
            } 
            if(s[i]=='+'){
                k = 1;
                cnt++;
                if(cnt==2) return 0;
            } 
            if(int(s[i])-int('0')>0&&int(s[i])-int('0')<10){
                break;
            }
        }
        int m;
        for(m = 0 ; m <= s.size()-2; m++){
            if(int(s[m])-int('0')>=0&&int(s[m])-int('0')<10&&(int(s[m+1])-int('0')<0||int(s[m+1])-int('0')>=10)){
                break;
            }
        }
        if(i==s.size()) return 0;
        if(i>m) return 0;
        int ans =0;
        for(int j = i; j <= m;j++){
            if(ans==2147483640){
                if(k==1&&int(s[j])-int('0')>7) return 2147483647;
                if(k==-1&&int(s[j])-int('0')>8) return -2147483648;
            }
            ans += int(s[j])-int('0');        
            if(j != m){
                if(ans>214748364&&k==1) return 2147483647;
                if(ans>214748364&&k==-1) return -2147483648;
                ans = ans*10;
            }
        }
        return k*ans;
        
    }*/
    int myAtoi(string s) {
    int sign = 1, base = 0, i = 0;
    while (s[i] == ' ') { i++; }
    if (s[i] == '-' || s[i] == '+') {
        sign = 1 - 2 * (s[i++] == '-'); 
    }
    while (s[i] >= '0' && s[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (s[i++] - '0');
    }
    return base * sign;
    }
};
// @lc code=end

