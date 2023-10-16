/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int left = 0;
        int right = nums.size()-1;
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }
            else{
                return -1;
            }
        }
        int mid = (left + right)/2;
        while(left+1 < right){
            mid = (left + right)/2;
            if(nums[mid] > nums[left]){
                left = mid;
            }
            if(nums[mid] < nums[right]){
                right = mid;
            }
        }
        int index = right;
        if(target >= nums[0] && target <= nums[index - 1]){
            return find(nums,target,0,index-1);
        }
        else if(target >= nums[index] && target <= nums[nums.size()-1]){
            return find(nums,target,index,nums.size()-1);
        }
        else{
            return -1;
        }
        return ans;
    }

    int find(vector<int>& nums,int target, int left, int right){
        int mid;
        while(left < right){
            mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                right = mid - 1;
            }
            if(nums[mid] < target){
                left = mid + 1;
            }
        }
        if(nums[left] == target) return left;
        return -1;
    }
};
// @lc code=end

