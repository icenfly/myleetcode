/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int mem[10010];
    int coinChange(vector<int>& coins, int amount) {
        memset(mem,0,sizeof(mem));
        return dp(coins, amount);
    }
    int dp(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        
        int res = INT_MAX;
        for(auto i : coins){
            int sub = 0;
            if(amount - i >= 0 && mem[amount - i] != 0){
                sub = mem[amount - i];
            }
            else{
                sub = dp(coins, amount - i);
                if(amount - i >= 0)
                    mem[amount - i] = sub;
            }
            
            if(sub == -1) continue;
            res = min(res, sub + 1);
            
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

