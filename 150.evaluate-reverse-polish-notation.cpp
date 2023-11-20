/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(string i : tokens){
            if(i[0] == '+'){
                int x = stack.top();
                stack.pop();
                int y = stack.top();
                stack.pop();
                stack.push(x+y);
            }
            else if(i[0] == '-' && i.size() == 1){
                int x = stack.top();
                stack.pop();
                int y = stack.top();
                stack.pop();
                stack.push(y-x);
            }
            else if(i[0] == '*'){
                int x = stack.top();
                stack.pop();
                int y = stack.top();
                stack.pop();
                stack.push(x*y);
            }
            else if(i[0] == '/'){
                int x = stack.top();
                stack.pop();
                int y = stack.top();
                stack.pop();
                int z = y/x;
                stack.push(z);
            }
            else{
                stack.push(stoi(i));
            }
        }
        return stack.top();
    }
};
// @lc code=end

