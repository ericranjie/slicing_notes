class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int i = 0, j = 0, n = nums.size();

        for (j = n - 1; j >= 1; j--) {
            if (nums[j] > nums[j - 1]) { // EPoint
                for (i = n - 1; i > j - 1; i--) {
                    if (nums[i] > nums[j - 1]) break;
                }
                swap(nums[i], nums[j - 1]);
                reverse(nums.begin() + j, nums.end());
                return;
            }
        }

        reverse(nums.begin(), nums.end());
/** My Deprecated Solution:
        for (j = n - 1; j >= 1; j--) {
            i = j - 1;
            if (nums[mx] < nums[j]) mx = j;
            if (nums[i] > nums[j]) continue;
            swap(nums[mx], nums[i]);
            return;
        }

        sort(nums.begin(), nums.end());
*/

/** Deprecate Forwarding Derivation:
        for (i = 0; i < n - 1; i++) {
            j = i + 1;
            while (nums[i] > nums[j]) continue;
            if (j == (n - 1)) {
                sort(nums.begin(), nums.end());
                return;
            }

            while (nums[i] < nums[j]) continue;
            if ()
        }   
*/
    }
};