/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sum;
        dfs(target, 0, sum, candidates, 0);
        return ans;
    }
    void dfs(int target, int curr, vector<int> sum, vector<int> candidates, int start){
        if(curr == target){
            ans.push_back(sum);
            return;
        }

        for(int i = start; i <= candidates.size()-1; i++){
            if(curr + candidates[i] <= target){
                sum.push_back(candidates[i]);
                dfs(target, curr + candidates[i], sum, candidates, i);
                sum.pop_back();
            }
        }
    }
};
// @lc code=end

