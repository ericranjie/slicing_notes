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
/** My Slow and Complicate Solution ==| */
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        int res = root->val;
        return dfs(root->left, res) + dfs(root->right, res);
    }

    int dfs(TreeNode *r, int cur) {
        if (!r) return 0;
        cur = cur * 10 + r->val;
        if (!r->left && !r->right) return cur;
        return dfs(r->left, cur) + dfs(r->right, cur);
    }
};