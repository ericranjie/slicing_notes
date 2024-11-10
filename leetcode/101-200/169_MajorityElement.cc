class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                res = num;
                ++cnt;
            } else (res == num) ? ++cnt : --cnt; // EPoint
        }
        return res;

/** My Deprecated Solution:
        int cnt = 0, i = 0, major = 0;
        for (i = 0; i < nums.size(); i++) {
            major = nums[i];
            cnt = 1;
            for (int j = i; j < nums.size(); j++) {
                if (major == nums[j]) {
                    ++cnt;
                } else {
                    if (--cnt <= 0) {
                        break;
                    }
                }
            }
            if (cnt > (nums.size() / 2)) return major;
        }
        return major;
*/
    }
};