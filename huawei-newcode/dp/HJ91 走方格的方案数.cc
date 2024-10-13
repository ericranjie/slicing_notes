#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    ++m; ++n;
    int i = 0, j = 0;
    int dp[9][9] = {0};
    for (i = 0; i < m; i++) { // POE:
        dp[i][0] = 1;
    }

    for (j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    for (i = 0; i < m; i++) {
        // if (j == 0) dp[i][j] = 1; // POE:
        for (j = 0; j < n; j++) {
            // if (i == 0) dp[i][j] = 1;
            if (i >= 1 && j >= 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                // cout << i << " - " << j << " - " << dp[i][j] << endl;
            }
        }
    }

    cout << dp[m - 1][n - 1];
    return 0;
}
// 64 位输出请用 printf("%lld")