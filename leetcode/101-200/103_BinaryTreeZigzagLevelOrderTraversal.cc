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
        if (!root) return {};
        vector<vector<int>> res;
        int level = 0;
        queue<TreeNode *> q{{root}};

        // q.push(root);
        while (!q.empty()) {
            vector<int> one;
            for (int i = q.size(); i > 0; i--) { // EPoint
            // for (int i = 0; i < q.size(); i++) {    
                TreeNode *t = q.front(); // EPoint: queue only have front
                q.pop();
                if (!t) continue; // EPoint: Boundary.
                if (t->left) q.push(t->left); 
                if (t->right) q.push(t->right);
                if (level % 2 == 0) one.push_back(t->val);
                else one.emplace(one.begin(), t->val);
            }
            res.push_back(one);
            level++;
        }

        return res;
    }
};