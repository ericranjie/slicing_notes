/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {}; // EPoint
        vector<vector<int>> res;
        vector<int> l;
        queue<Node *> q{{root}};

        res.push_back({root->val});
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                Node *t = q.front(); // EPoint: queue front not head
                if (!t) continue;
                for (Node *c : t->children) {
                    if (c) {
                        l.push_back(c->val);
                        q.push(c);
                    }
                }
                q.pop();
            }
            if (l.size() > 0) res.push_back(l); // EPoint
            l.clear();
        }

        return res;
    }
};