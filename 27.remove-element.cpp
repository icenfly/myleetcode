/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k =0;
        for(auto i : nums){
            if(i!=val){
                k++;
            }
        }
        int add = 0;
        for(int i = 0; i<k;i++){
            if(nums[i] == val){
                while(nums[k+add]==val){
                    add++;
                }
                swap(nums[i],nums[k+add]);
            }
        }
        return k;
    }
};
// @lc code=end

