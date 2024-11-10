class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      /**
       * @brief My Complex Descending Stack Solution:
       * 
       */
        int n = temperatures.size(), i = n - 1;
        stack<int> s;
        vector<int> res(n, 0); // EPoint

        s.push(i);
        res[i--] = 0;
        while (i >= 0) {
            int t = s.top();
            if (temperatures[i] < temperatures[t]) {
                s.push(i);
            } else {
                while (!s.empty() &&
                    temperatures[i] >= temperatures[s.top()]) {
                    // t = s.top() + 1; // EPoint:
                    s.pop();
                }
                // t = s.top(); // EPoint:
                if (s.empty()) t = i;
                else t = s.top(); // EPoint:
                s.push(i);
            }
            res[i--] = t - i; 
        }

        return res;
    }
};