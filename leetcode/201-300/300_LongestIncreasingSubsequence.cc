class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /**
         * DP O(n2) Solution:
         */
        vector<int> dp(nums.size(), 1);
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        
        return res;

/** Wrong Solution
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
            else if (nums[i] == nums[i - 1])
                dp[i] = 1;
            else
                dp[i] = dp[i - 1];
        }
        return dp[nums.size() - 1];
 */
    }
};