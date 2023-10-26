/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        int mx = 0;
        int maxcount = 0;
        int maxleft = 0;
        int maxright = 0;
        for(int i = 0; i <= height.size()-1; i++){
            if(height[i] == mx){
                maxright = i;
                maxcount ++;
            }
            if(height[i] > mx){
                mx = height[i];
                maxleft = i;
                maxcount = 1;
            }
        }
        if(maxcount >= 2){
            for(int i = maxleft + 1; i <= maxright - 1; i++){
                ans += mx - height[i];
            }
        }

        int left = 0;
        int right = 0;
        while(left <= height.size()-2 && right <= height.size()-1){
            if(height[left] >= height[right]){
                right++;
            }
            else{
                int mn = min(height[left],height[right]);
                for(int i = left + 1; i <= right - 1; i++){
                    ans += mn - height[i];
                }
                left = right;
            }
        }

        left = height.size()-1;
        right = height.size()-1;
        while(left >= 0 && right >= 1){
            if(height[right] >= height[left]){
                left --;
            }
            else{
                int mn = min(height[left],height[right]);
                for(int i = left + 1; i <= right - 1; i++){
                    ans += mn - height[i];
                }
                right = left;
            }
        }
        return ans;
    }
};
// @lc code=end

