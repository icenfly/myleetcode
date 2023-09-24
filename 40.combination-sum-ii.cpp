/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            if(curr + candidates[i] <= target){
                sum.push_back(candidates[i]);
                dfs(target, curr + candidates[i], sum, candidates, i+1);
                sum.pop_back();
            }
        }
    }
};
// @lc code=end

