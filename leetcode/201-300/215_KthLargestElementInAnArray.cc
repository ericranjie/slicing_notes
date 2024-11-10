class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int pos;
        while (l <= r) {
            pos = partition(nums, l, r);
            if (pos == k - 1) return nums[pos];
            else if (pos < k - 1) l = pos + 1;
            else r = pos - 1;
        }
        return nums[r];
    }

    int partition(vector<int>& nums, int start, int end) {
        int p = nums[start], l = start + 1, r = end;
        while (l <= r) {
            if (nums[l] < p && nums[r] > p)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= p) ++l; // EPoint: must be >=
            if (nums[r] <= p) --r; // EPoint: must be <=
        }
        swap(nums[start], nums[r]);
        return r;
    }
};