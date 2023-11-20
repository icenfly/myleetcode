/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int currSum = 0;
        int res = 0;
        while(i < nums.size() && j < nums.size()){
            currSum += nums[j];
            if(currSum >= target){
                if(res == 0) res = j-i+1;
                else res = min(res,j-i+1);
                currSum -= nums[i];
                i++;
                if(currSum >= target){
                    currSum -= nums[j];
                }
                else{
                    j++;
                }
            }
            else{
                j++;
            }
        }
        return res;
    }
};
// @lc code=end

