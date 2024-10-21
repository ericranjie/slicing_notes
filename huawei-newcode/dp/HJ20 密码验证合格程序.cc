#include <iostream>
#include <cctype>
#include <map>
#include <vector>
using namespace std;

/**
021Abc9Abc1


*/

void check(string t) {
    int n = t.size();
    // step-1:
    if (n <= 8) {
        cout << "NG" << endl;
        return;
    }

    // step-1.5:
    bool up = false, lo = false, // upper-lower-alphacase
         nu = false, ot = false; // number-other

    for (int i = 0; i < t.size(); i++) {
        if (isupper(t[i])) {
            up = true;
        } else if (islower(t[i])) {
            lo = true;
        } else if (isdigit(t[i])) {
            nu = true;
        } else {
            ot = true;
        }
    }

    // step-2:
    if ((int)up + (int)lo + (int)nu + (int)ot < 3) {
        cout << "NG" << endl;
        return;
    }

    // step-3:
    int mx = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (t[i] == t[j] && i != j) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    mx = max(mx, dp[i][j]);
                } else if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }
    }
    // cout << mx << endl;
    if (mx > 2) {
        cout << "NG" << endl;
        return;
    }

    // map<char, int> mp; // char -> laterest-index
    // int l = 0, r = 0; // left-right-pointer
    // for (int i = 0; i < t.size(); i++) {
    //     if (mp.count(t[i]) && mp[t[i] < i]) {
    //         l = mp[t[i]];
    //         r = i;
    //         if (r - l >= 2 &&
    //                 r < t.size()) {
    //             int count = 1;
    //             // start-checking:
    //             for (int j = 0; j + r < t.size(); j++) {
    //                 if (count > 2) {
    //                     cout << "NG" << endl;
    //                     return;
    //                 }
    //                 if (t[l] == t[r]) {
    //                     ++count;
    //                 }
    //                 ++l;
    //                 ++r;
    //             }
    //         }
    //     }
    //     mp[t[i]] = i;
    // }

    cout << "OK" << endl;
    return;
}

int main() {
    string t;
    while (getline(cin, t)) {
        check(t);
    }
    return 0;
}
// 64 位输出请用 printf("%lld")