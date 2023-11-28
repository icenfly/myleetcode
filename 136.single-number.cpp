/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uset;
        for(int i : nums){
            if(uset.find(i) != uset.end()){
                uset.erase(i);
            }
            else{
                uset.insert(i);
            }
        }
        return *(uset.begin());
    }
};
// @lc code=end

