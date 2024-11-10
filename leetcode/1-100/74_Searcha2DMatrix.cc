class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size(), i = 0, j = 0,
            l = 0, r = row * col - 1, m = 0;

        while (l <= r) {
            m = (l + r) / 2;
            if (target < matrix[m / col][m % col]) {
                r = m - 1;
            } else if (target > matrix[m / col][m % col]) {
                l = m + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};