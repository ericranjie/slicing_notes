#include <iostream>
// #include <vector>
using namespace std;

// need-recite-all:
int main() {
    int n;
    cin >> n;

    if (n == 1 || n == 2) { // Guard: no
        cout << -1 << endl;
        return 0;
    }
    if ((n - 1) % 2 == 0) {
        cout << 2 << endl;
        return 0;
    }
    if ((n % 2 == 0) &&
        (n % 4 == 0)) {
        cout << 3 << endl;
        return 0;
    }

    if ((n % 2 == 0) &&
        (n % 4 != 0)) {
        cout << 4 << endl;
        return 0;
    }

    return 0;
}

/** even = 1, odd = 0;
0 ^ 0 ^ 0 = 0 (3o = o);
1 ^ 0 ^ 0 = 1 (2o + 1e = e)
1 ^ 1 ^ 0 = 0 (1o + 2e = o)
1 ^ 1 ^ 1 = 1 (3e = e)
---
vn-1 = 0;
v2-2 = 0; vn-2 = v(n-1)-2 ^ 1; 
v3-3 = 0; vn-3 = v(n-1)-1 ^ v(n-1)-2 ^ v(n-1)-3;    v4-3 = v3-1 ^ v3-2 ^ v3-3;
v4-4 = 0; vn-4 = v(n-1)-2 ^ v(n-1)-3 ^ v(n-1)-4 =
v(n-2)-2 ^ 1 ^ v(n-2)-1 ^ v(n-2)-2 ^ v(n-2)-3 ^ v(n-1)-4 = 
v(n-2)-2 ^ 0 ^ v(n-2)-2 ^ v(n-2)-3 ^ v(n-1)-4 =
0 ^ v(n-2)-3 ^ v(n-1)-4
*/

/** odd = 1, even = 0;

*/

// TLE-failed-solution:
// thinking-for-several-days:
#if 0
int recur(int n, int i) { // n-row-i-index
    int r = 0;

    if (i <= 0) {
        r = 0; // even
        return r;
    } else if (i == 1) {
        r = 1; // odd
        return r;
    } else if (i == 2) {
        if ((n - 1) % 2 == 0) {
            return 0; // even
        } else {
            return 1; // odd
        }
    }

    if (n == i) { // odd
        r = 1;
        return r;
    }

    r = recur(n - 1, i - 2) ^ recur(n - 1, i - 1) ^
        recur(n - 1, i);

    return r;
}

int main() {
    int n;
    cin >> n;

    long long col = 1 + 2 * (n - 1);
    long long half = n;

    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    if ((n - 1) % 2 == 0) {
        cout << 2 << endl;
        return 0;
    }
    // vector<vector<bool>> v(n, vector<n, false>);

    int res = 1; // 1-means-odd
    for (int i = 1; i <= n; i++) { // loop-half:
        res = recur(n, i);
        if (res == 0) {
            cout << i << endl;
            return 0;
        }
    }

    // cout << to_string(1 ^ 1) << endl;
    // cout << to_string(0 ^ 0) << endl;
    // cout << to_string(0 ^ 1) << endl;
    cout << -1 << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
#endif

// #if 0
// r6c5 = 1 ^ r5c4 ^ r5c3 = 1 ^ (1 ^ )

// r2c1 = 0 ^ 0 ^ r1c1 = 2^0 1^1;
// r3c2 = 0 ^ r2c1 ^ r2c2 = 0 ^ r2c1 ^ 1 = 
// 0 ^ (0 ^ 0 ^ r1c1) ^ 1 = 3^0 2^1;
// // r4c2 = 0 ^ 1 ^ r3c2 = 4^0 3^1
// r4c3 = r3c1 ^ r3c2 ^ r3c3 = 1 ^ (3^0 2^1) ^ 1 =
// 3^0 4^1
// r7c5 = r6c3 ^ r6c4 ^ r6c5
//                 r5c3 ^ r5c4 ^ r5c5

// 3o = o; 2o + 1e = e; 1o + 2e = o; 3e = e
// 1:                       1   0   0   0   0  0
// 2:                -  1   1   1   0   0   0  0
// 3:               1   2   3   2   1   0   0  0
// 4:         - 1   3   6   7   6   3   1   0  0
// 5:        1  4   10  16  19  16  10  4   1  0
// 6:   - 1  5  15  30  45  51  45  30  15  5  1
// 7:   1 6  21 50  90  126 141 126 90  50  21 6  1
// 8: 1 7 28 77 161 266 357 393 357 266 161 77 28 7 1
//  1 8 36 112 
// 1 9 45 
// col3: ooo - oeo - ooe - oee - ooo - oeo - ooe - oee - ooo

// 0 0 0  0  0  1  0 0 0
// 0 0 0  0  1  1  1 0 0   
// 0 0 0  1  2  3  2 1 0
// 0 0 1  3  6  7  6 3 1
// 0 1 4  10 16 19
// 1 5 15 30 45 51
// #endif