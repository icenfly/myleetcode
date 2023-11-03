/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
private:
    static bool cmp(vector<int> i1, vector<int> i2){
        if(i1[0] == i2[0]){
            return i1[1] < i2[1];
        }
        return i1[0] < i2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0;
        int j = 1;
        while(j<=intervals.size()-1){
            if(intervals[i][1] >= intervals[j][0]){
                intervals[i][1] = max(intervals[j][1],intervals[i][1]);
                intervals.erase(intervals.begin()+j);
            }
            else{
                i ++;
                j ++;
            }
        }
        return intervals;
    }
};

// @lc code=end

