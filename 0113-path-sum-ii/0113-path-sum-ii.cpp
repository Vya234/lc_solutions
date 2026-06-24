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
    vector<vector<int>> res;
    void dfs(TreeNode* node, int targetSum, vector<int>& path){
        if(node==NULL) return;
        path.push_back(node->val);
        if(node->left==NULL && node->right==NULL &&node->val==targetSum) res.push_back(path);
        dfs(node->left,targetSum-node->val,path);
        dfs(node->right,targetSum-node->val,path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }
};