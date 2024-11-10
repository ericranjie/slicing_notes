class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
/** My Uncompleted Wrong Solution: */
        if (s.size() < 4 || s.size() > 12) return {};
        vector<string> res;
        string one;
        int n = s.size();

        recur(s, res, one, 1, 0);
        return res;
    }

    void recur(string &s, vector<string> &res, string &one, int level,
        int c) {
        if (c > s.size()) return;
        if (level == 4) {
            if (s.size() - c > 3 || s.size() - c < 0) {
                return;
            } else {
                one = one + s.substr(c, s.size() - c);
                res.push_back(one);
                return;
            }
        }

        int t = one.size(); // EPoint: not -1
        // if (t < 0) t = 0;

        one = one + s.substr(c, 1) + '.';
        recur(s, res, one, level + 1, c + 1);
        one.erase(t, one.size() - t);

        one = one + s.substr(c, 2) + '.';
        recur(s, res, one, level + 1, c + 2);
        one.erase(t, one.size() - t);

        one = one + s.substr(c, 3) + '.';
        recur(s, res, one, level + 1, c + 3);
        one.erase(t, one.size() - t);
    }
};