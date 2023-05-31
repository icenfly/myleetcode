/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int ans = 100000;
    for (int i = 0; i < nums.size(); i++) {
        int front = i + 1;
        int back = nums.size() - 1;
        while (front < back) {
            int sum = nums[i] + nums[front] + nums[back];
            
            if(sum==target) return sum;
            
            if (abs(target-sum)<abs(target-ans)){
                ans = sum;
            }
            else if (sum < target)
                front++;
            else if (sum > target)
                back--;
        }
    }
    return ans;
    }
};
// @lc code=end

