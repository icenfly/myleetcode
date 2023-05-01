/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int add = nums[0];
        vector<int> result = {nums[0]};
        for(int i = 1 ; i < nums.size(); i++){
            add += nums[i];
            result.push_back(add);
        }
        return result;
    }
};
// @lc code=end

