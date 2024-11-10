class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
/** My Deprecated Brute Force Solution:
        int area = 0, m = matrix.size(), n = matrix[0].size(),
            i = 0, j = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = (i >= 1) ? (
                    matrix[i][j] == '0' ? 0 : dp[i - 1][j] + 1) :
                    (matrix[i][j] - '0'); // EPoint

                if (dp[i][j] == 0) continue;

                int c = 1;
                if (matrix[i][j] == '1') area = max(area, 1);

                while (i - c >= 0 && j - c >= 0 &&
                    matrix[i - c][j - c] == '1') {
                    int cc = 0;
                    bool b = false; // break
                    for (cc = 0; cc <= c; cc++) {
                        if (dp[i][j - cc] < c + 1)
                            b = true;
                    }
                    if (b == true) break;
                    else
                        area = max(area, (c + 1) * (c + 1));

                    ++c;
                }
            }
        }

        return area;
*/
    }
};