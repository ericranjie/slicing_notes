class Solution {
public:
    string longestPalindrome(string s) {
        /**
         * @brief Grandyang's 2-Dimension DP Solution:
         * 
         */
        if (s.empty()) return "";
        if (s.size() == 1) return s; // EPoint:
        int n = s.size(), left = 0, len = 1; // EPoint:
        int dp[n][n];

        memset(dp, 0, n * n);

        dp[1][1] = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1; // EPoint: miss.
            for (int j = 0; j < i; j++) {
                dp[i][j] = (s[i] == s[j]) &&
                    (i - j > 1 ? dp[i - 1][j + 1] : 1);
                if (dp[i][j] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                }
            }
        }

        return s.substr(left, len);
    }
};