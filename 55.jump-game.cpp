/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> mem(nums.size(),true);
        return dfs(nums,0,mem);
    }
    bool dfs(vector<int>& nums, int index, vector<bool>& mem){
        int n = nums.size();
        if(index >= n-1){
            return true;
        }
        for(int i = 1; i <= nums[index]; i++){
            if(mem[index+i]){
                if(dfs(nums,index+i,mem)){
                    return true;
                }
                else{
                    mem[index+i] = false;
                }
            }
        }
        return false;
    }
};
// @lc code=end

