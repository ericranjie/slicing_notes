class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      /**
       * @brief Grandyang's Special Solution:
       * 
       */
        int res = 0, sum = 0;
        unordered_map<int, int> m{{0, 1}}; // EPoint

        for (int n : nums) {
            sum += n;
            res += m[sum - k];
            ++m[sum];
        }

        return res;
    }
};