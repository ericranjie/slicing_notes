#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
    string r;
    getline(cin, r);

    int n = r.size();
#if 1
    vector<vector<int>> dp;
    vector<int> o;
    o.resize(n, 0);
    for (int i = 0; i < n; i++) {
        dp.push_back(o);
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        // for (int j = 0; j < n; j++) {
        //     if (i > j) {
        //         v[i][j] = 0;
        //     }
        // }
    }
#endif

    int mx = 0;
    for (int i = n - 2; i >= 0; i--) { // POE: n - 2
        for (int j = i; j < n; j++) {
            if (i > j) continue;
            if (r[i] == r[j] &&
                j - i < 2) {
                dp[i][j] = dp[i + 1][j] + 1;
            }
            if (r[i] == r[j] &&
                j - i >= 2 &&
                i + 1 < n &&
                j - 1 >= 0 &&
                dp[i + 1][j - 1] == j - i - 1) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
// cout << dp[i][j] << " " << i << " " << j << endl;
            }
            // if (dp[i][j] > mx)
            // if (r[i])
            // cout << r.substr(i, j - i + 1) << endl;
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx;
    return 0;
}
//:0123456789
// 12HHHHA
// 12ABCBA
// 12ABCCA
// tmikrmvnkzwffmuycgffiqnrepltnfvnggtmwkzmpjpcfuhmdcdlrupmqbimvppbnqinwcuidfckveonfgcknihwztkvrikfunegxfboluzjhxkoxdvdxoczqdkyjziqmjnnrbvcolyxijemlujjofuojdwfhcgzmmnsznhbv
// 64 位输出请用 printf("%lld")