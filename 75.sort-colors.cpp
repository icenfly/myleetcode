/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3,0);
        for(auto i : nums){
            cnt[i] ++;
        }
        int index = 0;
        for(int i = 0; i < cnt.size(); i++){
            for(int j = 1; j <= cnt[i]; j++){
                nums[index] = i;
                index++;
            }
        }
        return;
    }
};
// @lc code=end

