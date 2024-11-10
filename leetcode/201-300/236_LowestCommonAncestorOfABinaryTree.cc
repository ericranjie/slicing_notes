/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root; // EPoint
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        
        if (l && r)
            return root;
        /**
        if ((l && r) || ((root == p || root == q) && (l || r))) // EPoint
            return root;
        
        else if (l && !r) return l;
        else if (!l && r) return r;
        */
        return l ? l : r;
    }
};