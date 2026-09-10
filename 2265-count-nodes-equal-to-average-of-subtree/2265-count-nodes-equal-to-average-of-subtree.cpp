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
    int result = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [left_sum, left_count] = dfs(node->left);
        auto [right_sum, right_count] = dfs(node->right);
        int total_sum = node->val + left_sum + right_sum;
        int total_count = 1 + left_count + right_count;
        if (node->val == total_sum / total_count) {
            result++;
        }
        return {total_sum, total_count};
    }
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
};