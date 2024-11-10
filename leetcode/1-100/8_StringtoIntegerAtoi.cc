class Solution {
public:
    int myAtoi(string s) {
        /** My Wrong Solution: */
        int i = 0, n = s.size(), l = 0, r = 0;
        long c = 0;
        bool sign = true;

        while (s[i] == ' ') ++i;

        if (s[i] == '-') {
            sign = false;
            i++;
        } else if (s[i] == '+') {
            sign = true;
            i++;
        }

        l = i;
        while (s[i] >= '0' && s[i] <= '9' && i < n) ++i;
        r = i;

        i = l;
        while (i < r && s[i] == '0') ++i;
        for (i; i < r; i++) {
            if (c < INT_MIN) { c = INT_MIN; break; }
            else if (c > INT_MAX) { c = INT_MAX; break; }
            if (i >= r) break;
            c = (long)(c * 10) + (long)(s[i] - '0');
        }

        if (sign == false) c *= -1;
        if (c <= INT_MIN) { c = INT_MIN; }
        else if (c >= INT_MAX) { c = INT_MAX; }        

        return c;
    }
};