class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string one("");

        recur(res, one, n, n);

        return res;
    }

    void recur(vector<string> &res, string &one, int l, int r) {
        if (l == 0 && r == 0) {
            res.push_back(one);
            // one.clear();
            return;
        }

        if (l < r) {
            if (l > 0) {
                one.push_back('(');
                recur(res, one, l - 1, r);
                one.pop_back();
            }
            if (r > 0) {
                one.push_back(')');
                recur(res, one , l, r - 1);
                one.pop_back();
            }
        } else if (l == r) {
            if (l > 0) {
                one.push_back('(');
                recur(res, one, l - 1, r);
                one.pop_back();
            }
        } else if (l > r) {
            return;
        }
    }
};