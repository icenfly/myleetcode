/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            vector<int> layer;
            int qsize = q.size();
            for(int i = 0; i < qsize; i++){
                layer.push_back(q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(level%2 == 1){
                res.push_back(layer);
            }
            else{
                reverse(layer.begin(),layer.end());
                res.push_back(layer);
            }
            level ++;
        }
        return res;
    }
};
// @lc code=end

