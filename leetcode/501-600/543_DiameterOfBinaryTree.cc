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
/** My Deprecated Solution:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        Postorder(root, res);

        return res;
    }

    int Postorder(TreeNode *root, int &res) {
        if (!root) return 0;
        int l = 0, r = 0, ml = 0, mr = 0;
        
        if (root->left) {
            l = 1 + Postorder(root->left, res);
            if (root->left->left)
                ml = ml + 1 + Postorder(root->left->left, res);
            if (root->left->right)
                ml = ml + 1 + Postorder(root->left->right, res);
                                
        }
        if (root->right) {
            r = 1 + Postorder(root->right, res);
            if (root->right->left)
                mr = mr + 1 + Postorder(root->right->left, res);
            if (root->right->right)
                mr = mr + 1 + Postorder(root->right->right, res);
        }
        int i = l + r; // Go Through the root
        
        res = max(max(i, ml), mr);
        return max(l, r);
    }
*/
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        MaxDepth(root, res);

        return res;
    }

    int MaxDepth(TreeNode *root, int &res) {
        if (!root) return 0;
        int l = 0, r = 0;
        l = MaxDepth(root->left, res);
        r = MaxDepth(root->right, res);
        res = max(l + r, res);
        return max(l, r) + 1;
    }
};