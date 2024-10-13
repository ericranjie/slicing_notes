#include <iostream>
#include <sys/types.h>
using namespace std;

int cnt(int n) {
    int i = 1, q = 1;
    while (n > 10) {
        n = n / 10;
        ++i;
        q *= 10;
    }
    return q * 10;
}

int main() {
    int n, res = 0;
    cin >> n;

    // cout << cnt(n);

    for (int i = 0; i <= n; i++) {
        int d = i * i;
        int c = cnt(i);
        int m = d % c;
        // cout << "d = " << d << " m = " << m << " i = " << i << endl;
        // if (i == 1) ++res;
        if (m == i) {
            ++res;
        }
    }

    cout << res;
    return 0;
}
// 64 位输出请用 printf("%lld")