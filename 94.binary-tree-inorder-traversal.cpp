/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        //inorder(root,res);
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr != nullptr || !s.empty()){
            while(curr != nullptr){
                s.push(curr);
                curr = curr->left;
            }
            res.push_back(s.top()->val);
            curr = s.top()->right;
            s.pop();
        }
        return res;
    }
    void inorder(TreeNode* root, vector<int> &res){
        if(root == nullptr){
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
// @lc code=end

