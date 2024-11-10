#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// recite:
int main() {
    int N, m;

    cin >> N; // cash-total
    cin >> m; // good-num
    N /= 10; // problem-branch:10-multi

    vector<vector<int>> price(m + 1, vector<int>(3, 0));
    vector<vector<int>> value(m + 1, vector<int>(3, 0));
    for (int i = 1; i <= m; i++) { // POE:
        int p, v, b;
        cin >> p >> v >> b;
        if (b == 0) { // belong=0
            price[i][0] = p / 10;
            value[i][0] = v;
        } else {
            if (price[b][1] != 0) {
                price[b][2] = p / 10;
                value[b][2] = v;
            } else {
                price[b][1] = p / 10;
                value[b][1] = v;
            }
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= N; j++) {
            int p = price[i][0], v = value[i][0];
            int p1 = price[i][1], v1 = value[i][1];
            int p2 = price[i][2], v2 = value[i][2];
            dp[i][j] = j >= p ?
                max(dp[i - 1][j - p] + p * v, dp[i - 1][j]) :
                dp[i - 1][j];
            dp[i][j] = j >= p + p1 ?
                max(dp[i - 1][j - p - p1] + p * v + p1 * v1, dp[i][j]) :
                dp[i][j];
            dp[i][j] = j >= p + p2 ?
                max(dp[i - 1][j - p - p2] + p * v + p2 * v2, dp[i][j]) :
                dp[i][j];
            dp[i][j] = j >= p + p1 + p2 ?
                max(dp[i - 1][j - p - p1 - p2] + p * v + p1 * v1 + p2 * v2, dp[i][j]) :
                dp[i][j];
        }
    }

    cout << dp[m][N] * 10;

    return 0;
}
// 64 位输出请用 printf("%lld")