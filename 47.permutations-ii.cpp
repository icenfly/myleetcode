/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int visit[30];
        memset(visit,0,sizeof(visit));
        dfs(0,nums.size(),nums,res, visit);
        return ans;
    }
    void dfs(int j,int numsize, vector<int>& nums, vector<int> res, int visit[]){
        if(j == numsize){
            ans.push_back(res);
            return;
        }
        for(int i = 0; i <= numsize-1; i++){
            if(visit[i]) continue;
            if(i >= 1 && nums[i] == nums[i-1] && !visit[i-1]) continue;
            visit[i] = 1;
            res.push_back(nums[i]);
            dfs(j+1,numsize,nums,res, visit);
            res.pop_back();
            visit[i] = 0;
        }
    }
};
// @lc code=end

