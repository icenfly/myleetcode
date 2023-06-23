/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
    bool dfs(TreeNode* l,TreeNode* r){
        if(l==nullptr&&r==nullptr){
            return true;;
        }
        if(l==nullptr&&r!=nullptr||l!=nullptr&&r==nullptr){
            return false;
        }
        if(l->val!=r->val){
            return false;
        }
        
        return dfs(l->left,r->left)&&dfs(l->right,r->right);
    }
};
// @lc code=end

