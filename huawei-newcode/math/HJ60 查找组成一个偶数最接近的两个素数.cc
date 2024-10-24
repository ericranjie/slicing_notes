#include <iostream>
#include <cmath>
using namespace std;

// recite:
bool veri(int a) { // verify-prime
    for (int i = 2; i < a / 2 + 1; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int a;
    cin >> a;

    int mn = a, r1, r2; // mn-result-1-2
    for (int i = 2; i < a / 2 + 1; i++) { // POE: must+1
        if (veri(i) && veri(a - i)) {
            if (abs(a - i - i) < mn) {
                r1 = i;
                r2 = a - i;
                mn = abs(a - i - i);
            }
        }
    }

    cout << r1 << endl;
    cout << r2 << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")