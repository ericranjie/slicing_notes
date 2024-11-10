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
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> lres;
        queue<TreeNode *> q{{root}};
        TreeNode *tmp;
        int i;

        while (!q.empty()) {
            int s = q.size();
            for (i = 0; i < s; i++) {
            // for (i = q.size(); i > 0; --i) {
                tmp = q.front(); q.pop();
                if (tmp && tmp->left) q.push(tmp->left);
                if (tmp && tmp->right) q.push(tmp->right);
                if (tmp) lres.push_back(tmp->val);
            }
            res.push_back(lres);
            lres.clear();
        }

        return res;
    }
};