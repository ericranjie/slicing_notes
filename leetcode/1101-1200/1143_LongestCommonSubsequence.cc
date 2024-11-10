class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size(), i = 0, j = 0,
            res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        bool match = false; // EPoint

        // dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (i = 0; i < m; i++) {
            if (text1[i] == text2[0] || match) { // EPoint
                dp[i][0] = 1;
                match = true;
                // break;
            }
        }

        match = false; // EPoint
        for (j = 0; j < n; j++) {
            if (text1[0] == text2[j] || match) { // EPoint
                dp[0][j] = 1;
                match = true;
                // break;
            }
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                dp[i][j] = (text1[i] == text2[j] ? dp[i - 1][j - 1] + 1 :
                    max(dp[i - 1][j], dp[i][j - 1]));

                // res = max(res, dp[i][j]); // EPoint
            }
        }

        return dp[m - 1][n - 1];
    }
};