#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int m = a.size(), n = b.size(), mx = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // int dp[m][n] = {0};
    // if (a[0] == b[0]) dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        if (b[0] == a[i]) { dp[i][0] = 1; mx = 1; } // POE:
    }
    for (int i = 0; i < n; i++) {
        if (a[0] == b[i]) { dp[0][i] = 1; mx = 1; } // POE:
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                mx = max(mx, dp[i][j]);
            }
        }
    }

    cout << mx;
    return 0;
}
// 64 位输出请用 printf("%lld")