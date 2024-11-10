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
    int widthOfBinaryTree(TreeNode* root) {
      /**
       * @brief Grandyang's Level Order Travesal Solution:
       * (Now it has problem.)
       */
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1}); // EPoint
        int res = 1;

        while (!q.empty()) {
            if (q.size() == 1) q.front().second = 1;
            int l = q.front().second, r = l, n = q.size();

            for (int i = 0; i < n; i++) {
                auto t = q.front();
                r = t.second;
                TreeNode *tp = t.first;
                q.pop();
                if (tp->left) q.push({tp->left, 2 * r});
                if (tp->right) q.push({tp->right, 2 * r + 1});
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};