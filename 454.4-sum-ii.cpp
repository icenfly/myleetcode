/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> m1;
        int res = 0;
        for(int i : nums1){
            for(int j : nums2){
                m1[i+j] ++;
            }
        }
        for(int i : nums3){
            for(int j : nums4){
                if(m1.find(-i-j) != m1.end()){
                    res += m1[-i-j];
                }
            }
        }
        return res;
    }
};
// @lc code=end

