#include <iostream>
#include <vector>
using namespace std;

// longest-increasing-subsequence:
// resite:
int main() {
    int n;
    vector<int> v;
    cin >> n;

    int t;
    while (cin >> t) {
        v.push_back(t);
        // cout << t;
    }

    vector<int> dp(n, 1);
    int mx = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j >= 0; j--) { // stuck-point:
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                mx = max(mx, dp[i]);
            }
        }
    }

    cout << mx;
    return 0;

    // vector<vector<int>> dp(n, vector<int>(n, 0));
    // dp[0][0] = 1;

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

    // int i = 0, j = 1, s = 1;
    // while (s < n) {
    //     i = 0; j = i + s;
    //     for (int k = i; k < j; k++) {
    //         dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
    //     }
    // }
}
// 64 位输出请用 printf("%lld")