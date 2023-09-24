/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        dfs(nums,res,0);
        return ans;
    }
    void dfs(vector<int>& nums,vector<int>& res,int start){
        ans.push_back(res);
        if(start == nums.size()) return;

        for(int i = start; i <= nums.size()-1; i++){
            res.push_back(nums[i]);
            dfs(nums,res,i+1);
            res.pop_back();
        }
    }
};
// @lc code=end

