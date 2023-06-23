/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    TreeNode *firstMistake, *secondMistake, *pre;
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(firstMistake->val,secondMistake->val);
    }
    void dfs(TreeNode* root){
        if(root==nullptr) return;
        dfs(root->left);
        if(pre&&!firstMistake&&pre->val>root->val){
            firstMistake = pre;
        }
        if(pre&&firstMistake&&pre->val>root->val){
            secondMistake = root;
        }
        pre = root;
        dfs(root->right);
    }

};
// @lc code=end

