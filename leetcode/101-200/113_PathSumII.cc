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
/** My Large Memory Solution */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;

        dfs(root, targetSum, res, path, 0);

        return res;
    }

    void dfs(TreeNode *r, int targetSum, vector<vector<int>> &res,
        vector<int> path, int s) {
        if (!r) return;
        if (!r->left && !r->right) {
            if (s + r->val == targetSum) {
                path.push_back(r->val);
                res.push_back(path);
            }
            path.clear();
            return;
        }
        path.push_back(r->val);
        s = s + r->val;

        dfs(r->left, targetSum, res, path, s);
        dfs(r->right, targetSum, res, path, s);
    }
};