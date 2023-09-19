/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int di = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return di;
    }
    int maxdepth(TreeNode* root){
        if(root == nullptr) return 0;
        int leftdepth = maxdepth(root -> left);
        int rightdepth = maxdepth(root -> right);
        di = max(di, leftdepth + rightdepth);
        return max(leftdepth, rightdepth) + 1;
    }
};
// @lc code=end

