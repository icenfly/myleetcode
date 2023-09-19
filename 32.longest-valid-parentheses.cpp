/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        bool flag = true;
        if(s == "" || s.size() == 1) return 0;
        if(s == "()") return 2;
        while(flag){
            flag = false;
            for(int i = 0; i <= s.size()-2; i++){
                if(s[i] == '('){
                    for(int j = i + 1; j <= s.size()-1; j++){
                        if(s[j] == '2') continue;
                        if(s[j] == '(') break;
                        if(s[j] == ')'){
                            flag = true;
                            //s = s.substr(0, i) + '2' + s.substr(i+1,j-i-1) + s.substr(j+1);
                            s.erase(j,1);
                            s.insert(j,"2");
                            s.erase(i,1);
                            
                        }
                    }
                }
            }
        }
        for(int i = 0; i <= s.size()-1; i++){
            if(s[i] == '2'){
                int cnt = 1;
                for(int j = i+1; j <= s.size()-1; j++){
                    if(s[j] == '2'){
                        cnt++;
                    }
                    else{
                        i = j;
                        break;
                    }
                }
                if(cnt>ans) ans = cnt;
            }
        }
        return ans*2;
    }
};
// @lc code=end

