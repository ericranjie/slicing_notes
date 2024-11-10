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
    /** Recursive Solution:
      */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        Preorder(root, res);

        return res;
    }

    void Preorder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        if (root) res.push_back(root->val);
        if (root->left) Preorder(root->left, res);
        if (root->right) Preorder(root->right, res);
    }
};