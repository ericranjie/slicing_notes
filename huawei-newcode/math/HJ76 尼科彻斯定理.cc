#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    bool even = (a % 2 == 0);
    int m = a * a, n = 0, s = 0;
    if (even) { // is even:
        n = a / 2; // half-length
        s = m - 1 - 2 * (n - 1); // POE:
    } else { // is odd:
        n = (a - 1) / 2;
        s = m - 2 * n;
    }

    for (int i = 0; i < a; i++) {
        if (i != a - 1)
            cout << s << "+";
        else
            cout << s;
        s += 2;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")