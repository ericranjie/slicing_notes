class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(),
            i = 0, j = 0, maxlen = 0;
        int dp[m][n];

        memset(dp, 0, sizeof(int) * m * n); // EPoint

        for (i = 0; i < m; i++) { // EPoint
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                maxlen = 1;
            }
        }
        for (j = 0; j < n; j++) {
            if (nums1[0] == nums2[j]) {
                dp[0][j] = 1;
                maxlen = 1;
            }
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] > 0 ?
                        dp[i - 1][j - 1] + 1 : 1;
                    maxlen = max(maxlen, dp[i][j]);
                } else {
                    dp[i][j] == 0;
                }
            }
        }

        return maxlen;
    }
};