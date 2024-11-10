class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int res = 0, cur = 1, pre = 0, n = nums.size(), cnt = 0;

        while (cur < n) {
            while (cur + 1 < n && nums[cur] == nums[cur + 1]) { // EPoint
                ++cnt;
                ++cur;
            }
            while (cur < n && nums[cur] == nums[pre]) { // EPoint
                ++cnt;
                ++cur;
            }
            if (cur >= n) { // EPoint: must have this step.
                while (++pre < n) nums[pre] = 0;
            }
            if (cur - pre > 1)
                swap(nums[cur], nums[pre + 1]);
            ++cur;
            ++pre;
        }

        return nums.size() - cnt;
    }
};