class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 0, r = num, m = 0;

        while (l <= r) {
            m = (l + r) / 2;
            if (m * m < num) l = m + 1; // EPoint
            else if (m * m > num) r = m - 1;
            else return true;
        }

        return ((l - 1) * (l - 1) == num) ? true : false;
    }
};