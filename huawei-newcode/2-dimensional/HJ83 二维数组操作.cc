#include <iostream>
using namespace std;

/*
-   0-1-2-3-4-5-6-7-8
0   0 0 0 0 0 0 0 0 0
1   0 0 0 0 0 0 0 0 0
2   0 0 0 0 0 0 0 0 0
3   0 0 0 0 0 0 0 0 0
*/

// 9 8
// 10 1 8 6
// 4
// 5
// 4 1
// 6 7
// 4 5 1 6
// 2
// 0
// 2 2

void verify(int v[]) {
    int m, n;
    int i1, j1, i2, j2;
    int r, c; // row-column
    int i3, j3;

    m = v[0], n = v[1], i1 = v[2], j1 = v[3], i2 = v[4],
    j2 = v[5], r = v[6], c = v[7], i3 = v[8], j3 = v[9];

    // step-1:
    if ((m >= 1 && m <= 9) && (n >= 1 && n <= 9)) {
        cout << "0" << endl;
    } else {
        cout << "-1" << endl;
        return;
    }

    // step-2:
    if ((i1 >= 0 && i1 < m) && (j1 >= 0 && j1 < n) &&
            (i2 >= 0 && i2 < m) && (j2 >= 0 && j2 < n)) { // POE: n - 1
        cout << "0" << endl;
    } else {
        cout << "-1" << endl;
    }

    // step-3:
    if (r >= 0 && r < m && m + 1 <= 9) { // POE: third-not-r
        cout << "0" << endl;
    } else {
        cout << "-1" << endl;
    }

    // step-4:
    if (c >= 0 && c < n && n + 1 <= 9) { // POE: <=
        cout << "0" << endl;
    } else {
        cout << "-1" << endl;
    }

    // step-5:
    if ((i3 >= 0 && i3 < m) && (j3 >= 0 && j3 < n)) {
        cout << "0" << endl;
    } else {
        cout << "-1" << endl;
    }

    return;
}

int main() {
    int count = 0, t;
    int v[10] = {0};
    while (cin >> t) {
        v[count] = t;
        // cout << t << " ";
        if (count >= 9) { // one-batch
            verify(v);
            // cout << endl;
            count = 0;
        } else { // POE:
            ++count;
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")