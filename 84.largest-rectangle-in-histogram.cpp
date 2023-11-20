/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        // goal1: get min[start][end]
        // goal2: cal maxof: (end-start+1)*min[start][end]
        int mn = 0;
        int cal = 1;
        for(int start = 0; start <= heights.size()-1; start++){
            cal = heights[start];
            if(cal <= mn) continue;
            mn = heights[start];
            for(int end = start; end <= heights.size()-1; end++){
                if(heights[end] < mn){
                    cal = mn*(end-start);
                    res = max(res,cal);
                    mn = heights[end];
                }
            }
            cal = mn*(heights.size()-start);
            res = max(res,cal);
        }
        return res;
    }
};
// @lc code=end

