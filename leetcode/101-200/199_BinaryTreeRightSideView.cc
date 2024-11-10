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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res, level;
        queue<TreeNode *> q{{root}};

        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front();
                q.pop();
                if (t) {
                    level.push_back(t->val);
                    if (t->left) q.push(t->left);
                    if (t->right) q.push(t->right);
                }
            }
            if (level.size() > 0) {
                // int t = level[level.size() - 1];
                int t = *(level.end() - 1);
                res.push_back(t);
                level.clear();
            }
        }

        return res;
    }
};