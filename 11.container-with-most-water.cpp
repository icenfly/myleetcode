/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
/*
    int maxArea(vector<int>& height) {
        int w_min[10010];
        int w_max[10010];
        int w[10010];
        for(int i= 0; i<=10009;i++){
            w_min[i] =100100;
            w_max[i] = -1;
            w[i] =0;
        }
        int mh = 0;
        
        for (int i = 0; i <= height.size()-1; i++){
            int h = height[i];
            if(w_min[h]>i){
                w_min[h] = i;
            } 
            if(w_max[h]<i){
                w_max[h] = i;
            }
            w[h] = 1;
            
            if(h>mh){
                mh = h;
            } 
        }
        int ans = 0;
        int mmn = 100100;
        int mmx = -1;
        for(int i = 10009 ; i >= 0;i++){
            if(w[i]==0) continue;
            if(mmn>w_min[i]) mmn = w_min[i];
            if(mmx<w_max[i]) mmx = w_max[i];
            if((mmx-mmn)*i > ans) ans = (mmx-mmn)*i;
        }
        return ans;
    }*/
    int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
    }
};
// @lc code=end

