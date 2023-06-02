/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        long long t1 = target;
        for (int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j< nums.size();j++){
                int front = j+1;
                int back = nums.size()-1;
                while (front < back) {
                    long long sum =(long long)nums[i]+(long long)nums[j]+(long long)nums[front]+(long long int)nums[back];
                    if (sum > t1)
                        back--;
                    else if (sum < t1)
                        front++;
                    else {
                        vector<int> qlet = {nums[i],nums[j], nums[front], nums[back]};
                        res.push_back(qlet);
                        while (front < back && nums[front] == qlet[2]) front++;
                        while (front < back && nums[back] == qlet[3]) back--;
                    }
                }
                while (j+1 < nums.size()&&nums[j+1] == nums[j]) j++;
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
// @lc code=end

