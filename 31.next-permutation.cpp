/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cnt = -1;
        for(int i = nums.size()-1; i >= 1; i--){
            if(nums[i]>nums[i-1]){
                cnt = i-1;
                int mn = 110;
                int j_index = -1;
                for(int j = i; j <= nums.size()-1; j++){
                    if(nums[j] > nums[i-1] && nums[j] <= mn){
                        mn = nums[j];
                        j_index = j;
                    }
                }
                swap(nums[i-1],nums[j_index]);
                break;
            }
        }
        int i = cnt+1;
        int j = nums.size()-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};
// @lc code=end

