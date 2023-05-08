/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int first = 0;
        int last = 1;
        while(last < prices.size()){
            if(prices[last]-prices[first]>mx){
                mx = prices[last]-prices[first];
            }
            else{
                if(prices[last]-prices[first]<0){
                    first = last;
                }
                // if there exist more profit beyond this point, first must be smaller
            }
            last ++;
        }
        return mx;
    }
};
// @lc code=end

