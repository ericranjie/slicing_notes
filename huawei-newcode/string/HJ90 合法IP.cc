#include <iostream>
#include <vector>
using namespace std;

// many-entrap:
void veri(string t) { // verify
    int n = 0, nn = 0, nd = 0; // number-of-num & dot

    bool nc = false; // number-continue
    int la = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '+' || t[i] == '-') { // POE:
            cout << "NO" << endl;
            return;
        }
        if (t[i] >= '0' && t[i] <= '9') {
            n *= 10;
            n += (t[i] - '0');
            if (!nc) {
                ++nn;
                la = t[i] - '0';
            }
            nc = true;
        } else if (t[i] == '.') {
            ++nd; nc = false;
            if (n > 255) {
                cout << "NO" << endl;
                return;
            }
            if (la == 0 && n > 0) { // POE:
                cout << "NO" << endl;
                return;
            }
            la = 0; // POE:
            n = 0; // POE: need-reset
        }
    }
    if (la == 0 && n > 0) { // POE:
        cout << "NO" << endl;
        return;
    }
    if (nd != 3) {
        cout << "NO" << endl;
        return;
    }
    if (nn != 4) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    return;
}

int main() {
    string t;
    vector<string> v;
    while (cin >> t) {
        v.push_back(t);
        // cout << t;
    }

    for (int i = 0; i < v.size(); i++) {
        veri(v[i]);
    }

    return 0;
}

// 1.3.8
// 01.2.3.8
// 1.0.3.8
// 0.2.3.8
// 1.2.3.08
// +1.2.3.8