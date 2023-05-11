/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a;
        if(root == nullptr){
            return a;
        }
        bfs(root,a);
        return a;
    }
    void bfs(TreeNode* root,vector<vector<int>> &a){
        vector<int> layer;
        queue<TreeNode*> q;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t!=nullptr){
                layer.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            else{
                a.push_back(layer);
                layer.resize(0);
                if(q.size()>0) q.push(nullptr);
            }
        }
    }
};
// @lc code=end

