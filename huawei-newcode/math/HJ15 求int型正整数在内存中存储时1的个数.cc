#include <iostream>
using namespace std;

int main() {
    int a, res = 0;
    cin >> a;

    while (a > 0) {
        res += (a & 1);
        a = a >> 1;
    }

    cout << res;
    return 0;
}
// 64 位输出请用 printf("%lld")