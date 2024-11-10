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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, 0, targetSum);
    }

    bool dfs(TreeNode *root, int sum, int target) {
        if (!root) return false;
        if (!root->left && !root->right) {
            if (sum + root->val != target) return false;
            else return true;
        }
        return (dfs(root->left, sum + root->val, target) ||
            dfs(root->right, sum + root->val, target));
    }
};