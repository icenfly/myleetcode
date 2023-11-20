/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> happy;
        while(n != 1){
            int next = 0;
            while(n > 0){
                next += pow(n%10,2);
                n = n / 10;
            }
            n = next;
            if(happy.find(n) != happy.end()){
                return false;
            }
            else{
                happy.insert(n);
            }
        }
        return true;
    }
};
// @lc code=end

