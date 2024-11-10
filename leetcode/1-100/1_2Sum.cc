class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, t;
        vector<int> res;
        unordered_map<int, int> m;

        for (i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (i = 0; i < nums.size(); i++) {
            t = target - nums[i];
            if (m.count(t) > 0 && m[t] != i) { // EPoint
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }

        return res;
    }
};