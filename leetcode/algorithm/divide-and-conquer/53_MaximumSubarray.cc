class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /** Grandyang's O(n) Solution:
        int cur_sum = 0, res = INT_MIN;

        for (int n : nums) {
            cur_sum = max(n, n + cur_sum);
            res = max(res, cur_sum);
        }

        return res;
        */
    }
};