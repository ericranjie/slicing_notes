#include <iostream>
using namespace std;

int main() {
    int a, mx = 0, c = 0;
    cin >> a;

    while (a >= 1) { // POE:
        if (a & 1 == 1) {
            if (c == 0) {
                c = 1;
                mx = max(mx, 1);
            } else {
                ++c;
                mx = max(mx, c);
            }
        } else {
            c = 0;
        }
        a = a >> 1;
    }

    cout << mx << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")