/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> ret;
        ret.push_back(-1);
        ret.push_back(-1);
        int left = 0;
        int right = nums.size()-1;
        if(right == -1) return ret;
        int mid = (left+right)/2;
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] >= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(left <= nums.size()-1 && nums[left] == target){
            ans.push_back(left);
        }
        else{
            return ret;
        }
        left = 0;
        right = nums.size()-1;
        mid = (left+right)/2;
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] <= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        ans.push_back(right);
        return ans;
    }
};
// @lc code=end

