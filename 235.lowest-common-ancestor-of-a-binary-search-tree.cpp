/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        int mn = min(p->val,q->val);
        int mx = max(p->val,q->val);
        dfs(root,mn,mx,ans);
        return ans;
    }
    void dfs(TreeNode* root, int p, int q,TreeNode* &ans){
        if(root==nullptr){
            return;
        }
        dfs(root->left,p,q,ans);
        if(p<=root->val&&root->val<=q){
            ans = root;
            return;
        }
        dfs(root->right,p,q,ans);
    }
};
// @lc code=end

