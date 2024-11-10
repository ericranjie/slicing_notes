class Solution {
public:
    string decodeString(string s) {
        /**
         * @brief My Incomplete Solution:
         * 
         */
        stack<int> st;
        string res, part, seg;
        int n = s.size(), i = 0, start = 0, end = 0, cnt = 0, carry = 1; // Start, End

        for (i = 0; i < n; i++) {
            if (isalpha(s[i]) || isalnum(s[i])) continue;
            else if (s[i] == '[') st.push(i);
            else if (s[i] == ']') {
                start = st.top(); st.pop();
                end = i;
                part = s.substr(start, end);
                int cur = start;
                while (isalnum(--cur)) {
                    cnt += (s[cur] - '0') * carry;
                    carry *= 10;
                }
                carry = 1; // Restore

                while (cnt-- > 0) {
                    seg += part;
                }

                int sbound = st.empty() ? 0 : s.top();
                seg = s.substr(sbound, cur) + seg;

                while (end < n && s[end] != ']') end++;
                int ebound = end;
                seg = seg + s.substr()
            }
        }

        return res;
    }
};