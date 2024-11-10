class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x, m = 0; // EPoint: must be long

        while (l <= r) {
            m = (l + r) / 2;
            if (m * m > x) r = m - 1;
            else if (m * m < x) l = m + 1;
            else return m;
        }

        return l - 1; // EPoint: must - 1
    }
};