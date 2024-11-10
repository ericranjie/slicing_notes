class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
/** My Deprecated Sulution:
        int i = 0, j = nums.size();

        if (j <= 1) return;
        i = j - 1;
        while (i >= 0 && j >= 0) {
            if (nums[j] != 0) {
                if (nums[i] == 0) {
                    swap(nums[i], nums[j]);
                    --j;
                }
                --i;
            } else {
                if (nums[i] == 0) {
                    j -= 2;
                    i -= 2;
                } else {
                    --j;
                    --i;
                }
            }
        }
    }
*/
};