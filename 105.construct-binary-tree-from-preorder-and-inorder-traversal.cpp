/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, preorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &index, int left, int right){
        if(left > right){
            return nullptr;
        }
        int pivot = left;
        while(pivot <= right && inorder[pivot] != preorder[index]){
            pivot ++;
        }
        TreeNode* newNode = new TreeNode(preorder[index]);
        index++;
        newNode -> left = build(preorder, inorder, index, left, pivot - 1);
        newNode -> right = build(preorder, inorder, index, pivot + 1, right);
        return newNode;
    }
};
// @lc code=end

