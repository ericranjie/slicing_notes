#include <iostream>
#include <vector>
using namespace std;

/*
- c d a b b a c c
c
d
a     x
b       x
b         x
a           x
c
c
*/

int main() {
    string t;
    getline(cin, t);

    int n = t.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    int mx = 1;
    for (int i = n - 1; i >= 0; i--) { // POE: must-reverse!
        for (int j = i; j < n; j++) {
            // checking:
            if (j - i == 1) {
                if (t[j] == t[i]) {
                    dp[i][j] = 2;
                    mx = max(mx, dp[i][j]);
                }
            } else if (j - i > 1) {
                if (t[j] == t[i]) {
                    if (dp[i + 1][j - 1] != 0) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                        mx = max(mx, dp[i][j]);
                    }
                }
            }
        }
    }

    cout << mx;
    // int mx = 1;

    // for (int i = 0; i < t.size(); i++) {
    //     int l = i, r = i, cur = 1;
    //     if (t[l] == t[r] &&
    //         (l > 1 && r < t.size() - 1)) {
    //         --l; ++r;
    //         mx = max(mx, cur);
    //     }
    // }

    return 0;
}
// cdabbacc
// 64 位输出请用 printf("%lld")