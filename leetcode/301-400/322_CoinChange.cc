class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1); // EPoint

        dp[0] = 0;

        sort(coins.begin(), coins.end());

        for (int i = 1; i < amount + 1; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);    
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
/** My Deprecated Solution:
        if (amount < 1) return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, -1);

        dp[0] = 0;

        sort(coins.begin(), coins.end());

        for (int i = 1; i < amount + 1; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (i - coins[j] >= 0 &&
                    dp[i - coins[j]] >= 0) {
                        dp[i] = dp[i - coins[j]] + 1;
                        break;
                    }
            }
        }

        return dp[amount];
*/
    }
};