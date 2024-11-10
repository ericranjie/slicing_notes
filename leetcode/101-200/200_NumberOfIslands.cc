class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int res = 0, i = 0, j = 0;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                // EPoint
                if (visited[i][j] == true || grid[i][j] == '0') continue;
                bfs(grid, visited, i, j);
                res++;
            }
        }

        return res;
    }

    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited,
        int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == '0' || visited[i][j] == true) return;
        visited[i][j] = true;
        bfs(grid, visited, i - 1, j);
        bfs(grid, visited, i, j - 1);
        bfs(grid, visited, i + 1, j);
        bfs(grid, visited, i, j + 1);
    }
};