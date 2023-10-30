/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = INT_MAX;
        //dfs(nums,0,0,ans,1);
        int N = nums.size();
        vector<int> dp(N,10010);
        dp[N-1] = 0;
        for(int i = N-2; i >= 0; i--){
            for(int jumplen = 1; jumplen <= nums[i]; jumplen ++){
                dp[i] = min(dp[i],dp[min(N-1,i+jumplen)]+1);
            }
        }
        return dp[0];
    }
    void dfs(vector<int>& nums, int index, int jumps, int &ans,int nextstart){
        if(index >= nums.size()-1){
            if(jumps < ans){
                ans = jumps;
            }
            return;
        }
        for(int j = nextstart; j <= nums[index] + index; j++){
            dfs(nums,j,jumps+1,ans,index+nums[index]+1);
        }
    }
};
// @lc code=end

