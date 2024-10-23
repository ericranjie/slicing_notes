#include <iostream>
#include <vector>
using namespace std;

// recite:
int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == i) {
            ++r;
        }
        for (int j = 2 * i; j <= n; j += i) {
            dp[j] += i;
        }
    }

    cout << r;
    return 0;
}
// 64 位输出请用 printf("%lld")