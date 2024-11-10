class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int l = 0, r = nums.size() - 1, m = 0;

        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                return m;
            }
        }

        return nums[l] == target ? l : -1;
    }
};