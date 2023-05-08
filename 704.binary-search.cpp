/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else if(nums[mid]>target){
                r = mid-1;
            }
        }
        return -1;
    }
};
// @lc code=end

