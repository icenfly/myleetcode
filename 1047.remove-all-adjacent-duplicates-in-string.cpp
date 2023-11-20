/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        stack.push(s[0]);
        for(int i = 1; i < s.size(); i++){
            if(!stack.empty() && s[i] == stack.top()/* && (i+1 >= s.size() || s[i+1] != stack.top())*/){
                while(!stack.empty() && stack.top() == s[i]){
                    stack.pop();
                }
            }
            else{
                stack.push(s[i]);
            }
        }
        string res = "";
        while(!stack.empty()){
            res += stack.top();
            stack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

