class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2]; // EPoint
        int diff = abs(target - res); // EPoint
        int tsum, tdiff;
        int i, j, k;

        sort(nums.begin(), nums.end());

        for (k = 0; k < nums.size() - 2; k++) {
            i = k + 1; j = nums.size() - 1;
            // diff = abs(target - nums[k]); // EPoint

            while (i < j) {
                tsum = nums[i] + nums[j] + nums[k];
                tdiff = abs(target - tsum);
                if (tdiff <= diff) {
                    res = tsum;
                    diff = tdiff; // EPoint
                }
                if (tsum < target) i++;
                else j--;
            }
        }

        return res;
    }
};