class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int res = 0, i = 0, j = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 0) dp[0][0] = 1;

        for (i = 1; i < n; i++) { // EPoint: m n wrong reverse.
            if (obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else break;
        }
        for (i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

/** My Deprecated BFS Solution:
  *
    void bfs(int r, int c, int endr, int endc, int &res,
        vector<vector<int>>& obstacleGrid) {
        if (r == endr && c == endc) {
            res++;
            return;
        }
        else if (r < 0 || r > endr || c < 0 || c > endc) return;
        else if (obstacleGrid[r][c] == 1) return;
        for (int i = 0; i < 4; i++) {
            int newr = r + d[i][0], newc = c + d[i][1];
            // if (newr >= 0 && newr <= endr && newc >= 0 && newc <= endc)
                bfs(newr, newc, endr, endc, res, obstacleGrid);
        }
    }
private:
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  */
};