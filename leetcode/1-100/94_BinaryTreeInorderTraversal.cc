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
/** Recursive Solustion:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Inorder(root, res);
        return res;
    }

    void Inorder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        Inorder(root->left, res);
        res.push_back(root->val);
        Inorder(root->right, res);
    }
*/
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> res;
        if (!root) return res;
        TreeNode *cur = root;

        s.push(cur);
        // cur = cur->left; // EPoint
        while (!s.empty()) {
            while (cur->left) { // EPoint
                cur = cur->left;
                s.push(cur);
            }
            while (!s.empty()) {
                cur = s.top(); s.pop();
                res.push_back(cur->val);
                if (cur->right) {
                    cur = cur->right; // EPoint
                    s.push(cur);
                    break;
                }
            }
        }
        
        return res;
    }
};