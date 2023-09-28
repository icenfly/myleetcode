/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = 0;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ans++;
            int k = q.size(); 
            for(int j = 1; j <= k; j++){
                TreeNode* r = q.front();
                q.pop();
                bool flag = false;
                if(r->left){
                    flag = true;
                    q.push(r->left);
                }
                if(r->right){
                    flag = true;
                    q.push(r->right);
                }
                if(!flag){
                    return ans;
                }
            }
            
        }
        return ans;
    }
};
// @lc code=end

