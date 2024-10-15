#include <iostream>
using namespace std;

int main() {
    int n, m = 0, q = 0;
    cin >> n;

    if (n == 0) cout << "0"; // POE:

    while (n > 0) {
        m = n % 10;
        cout << to_string(m);
        n = n / 10;
        // q = n / 10;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")