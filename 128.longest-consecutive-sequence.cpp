/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record(nums.begin(), nums.end());
        int res = 0;
        for(int i : nums){
            if(record.find(i) == record.end()) continue;
            record.erase(i);
            int prev = i-1;
            int next = i+1;
            while(record.find(prev) != record.end()){
                record.erase(prev);
                prev--;
            }
            while(record.find(next) != record.end()){
                record.erase(next);
                next++;
            }
            res = max(res, next - prev - 1);
        }
        return res;
    }
};
// @lc code=end

