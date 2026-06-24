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
    int count(TreeNode* node, long long targetSum){
        if(node==NULL) return 0;
        int ans=0;
        if(node->val==targetSum) ans++;
        ans+=count(node->left, targetSum-node->val);
        ans+=count(node->right, targetSum-node->val);   
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            cnt+=count(node,targetSum);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return cnt;
    }
};