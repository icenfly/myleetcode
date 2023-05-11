/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        dfs(root,flag);
        return flag;
    }
    long long number =-0x3f3f3f3f3f3f3f3f;
    void dfs(TreeNode* root, bool &flag){
        if(root==nullptr){
            return;
        }
        dfs(root->left,flag);
        if(number>=root->val){
            flag = false;
        }
        else{
            number=root->val;
        }
        dfs(root->right,flag);
    }
};
// @lc code=end

