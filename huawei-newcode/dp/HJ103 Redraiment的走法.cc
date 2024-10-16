#include <iostream>
#include <vector>
using namespace std;

// longest-increasing-subsequence:
int main() {
    int n;
    vector<int> v;
    cin >> n;

    int t;
    while (cin >> t) {
        v.push_back(t);
        // cout << t;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    // dp[0][0] = 1;
    int r = 0;
    // for (int i = 0; i < n; i++) {
    //     dp[i][j]
    // }

    // for (int i = 0; i < n; i++) {
    //     int mx = 1; // current-max
    //     for (int j = i + 1; j < n; j++) { // POE: j from i


    //         // if (v[j] > mx) {
    //         //     dp[i][j] = dp[i][j - 1] + 1;
    //         //     cout << j << " " << v[j] << " " << mx << endl;
    //         // }
    //         // mx = max(mx, v[j]);
    //         // r = max(r, dp[i][j]);
    //     }
    // }

    int i = 0, j = 1, s = 1;
    while (s < n) {
        i = 0; j = i + s;
        for (int k = i; k < j; k++) {
            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }

    cout << r;
    return 0;
}
// 64 位输出请用 printf("%lld")