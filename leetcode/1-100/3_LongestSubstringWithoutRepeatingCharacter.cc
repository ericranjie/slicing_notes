class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, l = -1; // EPoint: left init must be -1.
        unordered_map<int, int> m;
        int i = 0;

        for (i = 0; i < s.size(); i++) {
            if (m.count(s[i]) && l < m[s[i]]) l = m[s[i]]; // EPoint

            if (i - l >= res) {
                res = i - l;
            }

            m[s[i]] = i;
        }

        return res;
    }
};