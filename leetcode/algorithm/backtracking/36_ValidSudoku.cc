class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> r(9, vector<bool>(9, false)); // row
        vector<vector<bool>> c(9, vector<bool>(9, false)); // column
        vector<vector<bool>> b(9, vector<bool>(9, false)); // board(cell)

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue; // POE:
                int o = board[i][j] - '1'; // POE:not-0
                if (r[i][o] || c[o][j] || b[3 * (i / 3) + j / 3][o]) { // POE:
                    return false;
                }
                r[i][o] = true;
                c[o][j] = true;
                b[3 * (i / 3) + j / 3][o] = true;
            }
        }

        return true;
    }
};