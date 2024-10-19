#include <iostream>
#include <math.h>
using namespace std;

/*
19683 = 27^3
-
19900
-
21952 = 28^3

------
139 * 139 * 139 = 2685619

2744 = 14^3
-
2700
-
2197 = 13^3
*/

int main() {
    double f;
    cin >> f;

    bool minus = false; // POE:
    int d = (int)(f * 1000);
    if (d < 0) {
        minus = true;
        d *= (-1);
    }
    // cout << d << endl;

    // cheat: 28
    // for (int i = 0; i < 30; i++) {
    // }
    int l = 0, r = 28;
    while (l + 1 < r) { // POE:
        int m = (l + r) / 2; // lower-bound
        if (m * m * m <= d) {
            l = m;
        } else {
            r = m;
        }
        // cout << "m: " << m << " " << l << " " << r << endl;
    } 

    int res = 0;
    if ((d - l * l * l) < (r * r * r - d)) {
        res = l;
        // cout << l;
    } else {
        res = r;
        // cout << r;
    }
    int m = res % 10; // one-digit
    int q = res / 10; // ten-digit
    if (minus) {
        cout << "-";
    }
    cout << to_string(q) << "." << to_string(m);

    // double res = (double)(l / 10);
    // cout << res;

    return 0;
}
// 2.7 -> 1.4
// -5 -> -1.7
// 64 位输出请用 printf("%lld")