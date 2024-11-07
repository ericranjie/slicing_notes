#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

#if 0
// leetcode:44
// recite:2d-dp-grandyang-solution
// **Za
// 0QZza
#endif

bool valid(char a) {
    if ((a >= 'A' && a <= 'Z') ||
        (a >= 'a' && a <= 'z') ||
        (a >= '0' && a <= '9') ||
        a == '.') { // POE:
        return true;
    }
    return false;
}

bool equal(char a, char b) {
    if (a >= 'A' && a <= 'Z') {
        a += 32;
    }
    if (b >= 'A' && b <= 'Z') { // POE:
        b += 32;
    }
    cout << "- : " << a << " " << b << endl;
    if (a == b || a == '?' || b == '?') {
        return true;
    } else {
        return false;
    }
}

int main() {
    string p, t; // pattern and target
    getline(cin, p);
    getline(cin, t);
    int i = 0, j = 0;

    int m = t.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < t.size(); i++) {
        if (t[i] >= 'A' && t[i] <= 'Z') {
            t[i] += 32;
        }
        if (!valid(t[i])) {
            cout << "false";
            return 0;
        }
    }

    for (int i = 0; i < p.size(); i++) {
        if (p[i] >= 'A' && p[i] <= 'Z') {
            p[i] += 32;
        }
    }

    dp[0][0] = true;
    for (int i = 1; i < n; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i <= m; i++) { // POE:1
        for (int j = 1; j <= n; j++) { // POE:1
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j - 1] &&
                    (t[i - 1] == p[j - 1] || p[j - 1] == '?');
            }
        }
    }

    if (dp[m][n] == false)
        cout << "false";
    else
        cout << "true";
    return 0;
}
// a*?*c
// a@c
// false
// true
// t?t*1*.*
// txt12.xls
// true - false
// 64 位输出请用 printf("%lld")