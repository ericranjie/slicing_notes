class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size(), i = 0;

        if (intervals.size() <= 0) return res;

        sort(intervals.begin(), intervals.end()); // EPoint: must sort

        int s = intervals[0][0], e = intervals[0][1];

        for (i = 1; i < n; i++) {
            if (intervals[i][0] <= e) {
                e = max(intervals[i][1], e); // EPoint: must be e.
                continue;
            }
            res.push_back({s, e});
            s = intervals[i][0];
            e = intervals[i][1];
        }
        res.push_back({s, max(intervals[i - 1][1], e)});

        return res;
    }
};