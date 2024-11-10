class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, i = 0, min_price = prices[0];

        for (i = 1; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            if (prices[i] > min_price) {
                res = max(res, prices[i] - min_price); // EPoint
            }
        }

        return res;
    }
};