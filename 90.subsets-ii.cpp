/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        int visit[30];
        memset(visit,0,sizeof(ans));
        sort(nums.begin(),nums.end());
        dfs(nums,res,0,visit);
        return ans;        
    }
    void dfs(vector<int>& nums,vector<int>& res,int start,int visit[]){
        ans.push_back(res);
        if(start == nums.size()) return;

        for(int i = start; i <= nums.size()-1; i++){
            if(i >= 1 && nums[i-1] == nums[i] && !visit[i-1]) continue;
            visit[i] = 1;
            res.push_back(nums[i]);
            dfs(nums,res,i+1,visit);
            res.pop_back();
            visit[i] = 0;
        }
    }
};
// @lc code=end

