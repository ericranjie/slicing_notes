#include <iostream>
#include <cmath>
using namespace std;

// resite:
int main() {
    int n;
    cin >> n;

    int k = sqrt(n);
    // cout << n << endl;

    for (int i = 2; i < k + 1; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }

    if (n != 1) { // POE:
        cout << n;
    }
    // int i = 2;
    // while (n >= 1) {
    //     int quo = n / i;
    //     int mod = n % i;
    //     if (mod == 0) {
    //         cout << i << " ";
    //     }
    // }

    return 0;
}
// 64577
// 64 位输出请用 printf("%lld")