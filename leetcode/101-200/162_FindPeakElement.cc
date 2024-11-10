class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m = 0;

        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] > nums[m + 1])
                r = m;
            else
                l = m + 1;
        }

        return r; // EPoint: not m but r
    }
/** My Deprecate Solution: (Divide and Conquer)
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) return 0;
            else return 1;
        }
        int res = 0;

        res = dac(nums, 0, (nums.size() - 1) / 2);
        if (res != -1) return res;
        res = dac(nums, (nums.size() - 1) / 2,
            nums.size() - 1);
        if (res != -1) return res;

        return res;
    }

    int dac(vector<int> &nums, int l, int r) {
        if (l < 0 || r >= nums.size()) return -1;
        if (l >= r) return -1;
        int m = (l + r) / 2, res = 0;
        bool nol = false, nor = false;

        if (m == 0 &&
            m + 1 <= nums.size() - 1) {
            if (nums[m] > nums[m + 1])
                return 0;   
            else {
                return -1;
                // nol = true;
            }
        }
        if ((m == nums.size() - 1) &&
            (m - 1 >= 0)) {
            if (nums[m - 1] < nums[m])
                return m;
            else
                return -1;
                // nor = true;
        }

        if (m - 1 >= 0 &&
            m + 1 <= nums.size() - 1 &&
            nums[m - 1] < nums[m] &&
            nums[m] > nums[m + 1])
            return m;

        if (!nol) res = dac(nums, l, m);
        if (res != -1) return res;
        if (!nor) res = dac(nums, m, r);
        if (res != -1) return res;

        return -1;
    }
*/
};