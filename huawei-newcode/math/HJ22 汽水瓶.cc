#include <iostream>
using namespace std;

int helper(int num) {
    int quo = 0, mod = 0, cur = num, res = 0;

    while (cur > 1) {
        quo = cur / 3;
        mod = cur % 3;
        res += quo;

        cur = quo + mod;
        if (cur % 3 == 2 && cur / 3 == 0) { // POE:
            cur += 1;
        }
    }

    return res;
}

int main() {
    int raw[10] = {0};
    for (int i = 0; i < 10; i++) {
        cin >> raw[i];
        if (raw[i] == 0) break;
        cout << helper(raw[i]) << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")