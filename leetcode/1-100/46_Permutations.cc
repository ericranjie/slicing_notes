class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one, visited(nums.size(), 0); // EPoint: init size.
        int i = 0;
       
        dfs(nums, res, one, visited, 0); // EPoint

        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int> &one,
        vector<int> &visited, int level) {
        if (level == nums.size()) {
            res.push_back(one);
            return;
        }

        for (int i = 0; i < nums.size(); i++) { // EPoint
            if (visited[i] == 1) continue;
            visited[i] = 1;
            one.push_back(nums[i]);
            dfs(nums, res, one, visited, level + 1);
            one.pop_back();
            visited[i] = 0;
        }
    }
};