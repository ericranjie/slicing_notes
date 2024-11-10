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
    bool isBalanced(TreeNode* root) {
        bool res = true;

        Preorder(root, res);

        return res;
    }

    int Preorder(TreeNode *root, bool &res) {
        if (!root) return 0;
        int l = 0, r = 0;
        l = Preorder(root->left, res);
        if (res == false) return 0; // Branch cut: no matter return what.
        r = Preorder(root->right, res);
        if (res == false) return max(l, r) + 1;

        if (abs(l - r) > 1) res = false;

        return max(l, r) + 1;
    }
};