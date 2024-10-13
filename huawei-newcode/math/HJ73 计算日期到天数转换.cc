#include <iostream>
using namespace std;

int main() {
    int y, m, d, res = 0;
    cin >> y >> m >> d;

    int md[12] = {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    if (m == 1) {
        cout << d << endl;
        return 0;
    }
    else if (m > 1) {
        for (int i = 0; i < m - 1; i++) {
            res += md[i];
        }
        res += d;
        if ((y % 4 == 0 && y % 100 != 0) ||
            (y % 400 == 0)) {
            if (m > 2) res++;
        }
    }

    cout << res << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")