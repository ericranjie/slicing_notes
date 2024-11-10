class Solution {
public:
    int maxProfit(vector<int>& prices) {
      /**
       * @brief (Screw Up):
       * 
       */
        int res = 0, i = 0;
        for (i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i])
                res += prices[i + 1] - prices[i];
        }
        return res;
    }
};