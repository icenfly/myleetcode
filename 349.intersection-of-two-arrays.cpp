/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> intersec(nums1.begin(),nums1.end());
        unordered_set<int> res;
        for(auto i : nums2){
            if(intersec.find(i) != intersec.end()){
                res.insert(i);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};
// @lc code=end

