class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      /**
        * @brief: My Deprecated Matrix Solution:
        int n = nums.size(), l = 0, r = 0, i = 0;
        vector<int> s(n, 0);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        */
        unordered_set<int> s;
        int sum = 0, rem = 0, pre = 0;

        for (int n : nums) {
            sum += n;
            rem = (k == 0) ? sum : sum % k;
            if (s.count(rem)) return true;
            s.insert(pre);
            pre = rem;
        }

        return false;
    }
};