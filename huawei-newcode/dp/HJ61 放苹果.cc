#include <iostream>
#include <vector>
using namespace std;

// recite: dp-solution:

#if 0
int recur(int m, int n) {
    if (m < 0 || n < 0) {
        return 0;
    } else if (m == 1 || n == 1) {
        return 1;
    } else {
        return recur(m, n - 1) + recur(m - n, n);
    }
}
#endif

int main() {
    int m, n, res = 0;
    cin >> m >> n; // m-apple-n-plate

    // cout << recur(m, n);


#if 1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    dp[1][1] = 1;
    // dp[1][0] = 1;
    // dp[0][1] = 1;

    for (int i = 0; i <= n; i++) { // one-apple
        dp[1][i] = 1;
        dp[0][i] = 1;
    }

    for (int i = 0; i <= m; i++) { // one-plate POE:
        dp[i][1] = 1;
        // dp[i][0] = 1;
    }
    // cout << m << " " << n << endl;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) { // POE: not-2
            // cout << i << " " << j << endl;
            if (i >= j) {
                dp[i][j] = dp[i][j - 1] + // one-plant-empty
                    dp[i - j][j];
            } else {
                dp[i][j] = dp[i][i];
            }
        }
    }

    cout << dp[m][n];
#endif
    return 0;
}
// 2 5
#if 0
void re(vector<int> p, int n, int a, int &res,
    set<set<int>> &st) {

    if (a == 0) {
        set<int> t;
        for (int i = 0; i < n; i++) {
            t.insert(p[i]);
        }
        if (st.count(t)) { return; } 
        else { st.insert(t); res++; return; }
    }

    for (int i = 0; i < n; i++) {
        ++p[i];
        re(p, n, a - 1, res, st);
        --p[i];
    }

    return;
}

int main() {
    set<set<int>> st;
    int m, n, res = 0;
    cin >> m >> n;

    vector<int> p;
    p.resize(n, 0);

    re(p, n, m, res, st);
    cout << res << endl;

    return 0;
}
#endif

// // 64 位输出请用 printf("%lld")

// int once(int r[]) {
//     int imax = 0, imin = 0, imid = 0;
//     int mx = r[0], mn = r[0];
//     for (int i = 0; i < 3; i++) {
//         if (r[i] >= mx) {
//             mx = r[i];
//             imax = i;
//         }
//         if (r[i] <= mn) {
//             mn = r[i];
//             imin = i;
//         }
//     }
//     for (int i = 0; i < 3; i++) {
//         if (i == imax) continue;
//         else if (i == imin) continue;
//         imid = i;
//     }
//     return r[imax] * 4 + r[imid] * 2 + r[imin];
// }

// void re(int r[], unordered_set<int> &st, &res) {
//     int o = once(r);
//     if (st.count(o)) return;
//     else st.insert(o);

//     // int t[3];
//     // for (int i = 0; i < 3; i++) {
//     //     t[i] = r[i];
//     // }

//     // if (t[0] >= 1) {
//     //     t[0] -= 1;
//     //     t[1] += 1;
//     //     re(t, st, res);
//     // }

//     if (r[0] >= 1) {
//         r[0]--; r[1]++;
//         re(r, st, res);
//         r[0]++; r[1]--;
//     } else if (r[0] == 0 && r[1] >= 1) {
//         r[1]--; r[2]++;
//         re(r, st, res);
//         r[1]++; r[2]--;
//     }
//     // } else if (r[0] == 0 && r[1] == 0 && r[2] >= 1) {
//     //     r[1]--; r[2]++;
//     //     re(r, st, res);
//     //     r[1]++; r[2]--;
//     // }

//     return;
// }
