class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int i, j, k;
        int target;

        sort(nums.begin(), nums.end());

        for (k = 0; k < nums.size() - 2; k++) {
            if (nums[k] > 0) break; // EPoint
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            i = k + 1;
            j = nums.size() - 1;
            target = 0 - nums[k];
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) i++; // EPoint
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    ++i;
                    --j;
                } else if (nums[i] + nums[j] < target) { // EPoint
                    ++i;
                } else {
                    --j;
                }
            }
        }

        return res;
    }
};