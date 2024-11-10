class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i = 0, res = 0;
        if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); // EPoint
        for (i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};