class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        if (nums.size() == 1 && nums[0] == target) return {0, 0};
        if (nums[0] == target && nums[nums.size() - 1] == target)
            return {0, static_cast<int>(nums.size()) - 1};
        int l = 0, r = nums.size() - 1, m = 0;

        while (l <= r) { // EPoint: must have =
            m = (l + r) / 2;
            if (target < nums[m]) r = m - 1;
            else if (target > nums[m]) l = m + 1;
            else {
                int i = m;
                while (i > 0 && nums[i - 1] == nums[i]) --i; // EPoint
                l = i;
                i = m;
                while ((i < nums.size() - 1) && nums[i + 1] == nums[i]) ++i;
                r = i;
                return {l, r};
            }
        }
        return {-1, -1};
    }
};