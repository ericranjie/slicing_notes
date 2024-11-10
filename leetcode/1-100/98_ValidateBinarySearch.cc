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
    bool isValidBST(TreeNode* root) {
        
        /** My Wrong Recursive Solution:
        if (!root) return true;
        if (!isValidBST(root->left) || !isValidBST(root->right)) return false;
        if (root->left && root->left->val >= root->val) return false;
        if (root->right && root->val >= root->right->val) return false;
        return true;
        */
        if (!root) return true;
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode *root, long mn, long mx) { // EPoint: must be long.
        if (!root) return true;
        if (mn >= root->val || mx <= root->val) return false;
        return isValid(root->left, mn, root->val) &&
            isValid(root->right, root->val, mx);
    }
};