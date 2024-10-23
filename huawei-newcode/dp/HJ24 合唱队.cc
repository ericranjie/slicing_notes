#include <iostream>
#include <vector>
using namespace std;

// longest-increase-subsequence:
// recite:
int main() {
    int n;
    cin >> n;
    vector<int> v;

    int t;
    while (cin >> t) {
        v.push_back(t);
        // cout << t << " ";
    }
    // cout << endl;

    int r = 0;

    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    for (int i = 0; i < v.size(); i++) {
        int mxi = 0; // increasing
        for (int j = i; j >= 0; j--) {
            if (v[j] < v[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
                mxi = max(mxi, inc[i]);
            }
        }
        // POE:
    }

    for (int i = v.size(); i >= 0; i--) {
        int mxd = 0; // decreasing
        for (int j = i; j < v.size(); j++) {
            if (v[j] < v[i]) {
                dec[i] = max(dec[i], dec[j] + 1);
                mxd = max(mxd, dec[i]);
            }
        }
    }

    int p = 0;
    for (int i = 0; i < v.size(); i++) {
        p = max(p, inc[i] + dec[i] - 1);
    }

    cout << v.size() - p;
    return 0;
}
// 64 位输出请用 printf("%lld")