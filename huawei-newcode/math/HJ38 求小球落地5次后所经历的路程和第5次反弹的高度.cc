#include <iostream>
using namespace std;

// cheat-solution:
int main() {
    double d;
    cin >> d;

    double r = 0;
    for (int i = 0; i < 5; i++) {
        r = r + d + d / 2;
        d /= 2;
    }
    r -= d;
    cout << r << endl;
    cout << d << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")