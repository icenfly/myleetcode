/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int N = num1.size() + num2.size();
        string ans(N,'0');
        for(int i = 0; i < num2.size(); i++){
            int d2 = num2[i] - '0';
            for(int j = 0; j < num1.size(); j++){
                int d1 = num1[j] - '0';
                int z = i + j;
                int c = ans[z] - '0';
                int m = d1 * d2 + c;
                ans[z] = (m % 10) + '0';
                ans[z+1] += (m / 10);
            }
        }
        if(ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

