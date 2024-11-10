class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(m + n) Solution: Too much time.
        int r = matrix.size(), c = matrix[0].size(), i = r - 1,
            j = 0;

        while (true) {
            if (i < 0 || j > c - 1) return false; // EPoint
            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) i--;
            else j++;
        }

        //return false;
        // Binary Search Solution:
    }
};