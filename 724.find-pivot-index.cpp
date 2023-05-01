/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for(int i = 1; i < nums.size(); i++){
            right += nums[i];
        }
        if(left == right) return 0;
        for(int i = 1; i < nums.size(); i++){
            left += nums[i-1]; 
            right -= nums[i];
            if(left == right) return i;
        }
        return -1;
    }
};
// @lc code=end

