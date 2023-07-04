/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int pre = -200;
        for(auto i: nums){
            if(i!=pre){
                pre = i;
                nums[k] = pre;
                k++;
            }
        }
        return k;
    }
};
// @lc code=end

