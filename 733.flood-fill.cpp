/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]) return image;
        dfs(image,sr,sc,color,image[sr][sc],image.size(),image[0].size());
        return image;
    }
    void dfs(vector<vector<int>>& image,int r, int c, int color,int original,int m,int n){
        image[r][c] = color;
        int a[5] = {0,0,0,1,-1};
        int b[5] = {0,1,-1,0,0};
        for(int i = 1; i<=4;i++){
            if((r+a[i]>=0)&&(r+a[i]<m)&&(c+b[i]>=0)&&(c+b[i]<n)&&image[r+a[i]][c+b[i]]==original){
                dfs(image,r+a[i],c+b[i],color,original,m,n);
            }
        }
    }
};
// @lc code=end

