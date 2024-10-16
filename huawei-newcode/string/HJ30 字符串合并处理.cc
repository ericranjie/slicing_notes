#include <iostream>
#include <algorithm>
using namespace std;

char trans(char c) { // must-be-uppercase
    int d = 0; // decimal
    if (c >= '0' && c <= '9') {
        d = c - '0';
    } else if (c >= 'A' && c <= 'F') {
        d = (c - 'A') + 10;
    }

    int r = 0, l = 8;
    while (d > 0) {
        int i = d % 2;
        r += (i * l);

        l /= 2;
        d = d >> 1;
    }
    // cout << c << " " << to_string(r) << endl;
    if (r >= 0 && r <= 9) {
        return (char)('0' + r);
    } else if (r >= 10 && r <= 15) {
        return (char)('A' + (r - 10));
    }

    return c; // error
}

int main() {
    string t;
    getline(cin, t);

    // step-1:
    int space = 0;
    for (int i = 0; i < t.size(); i++) {
        if (space > 0) {
            t[space] = t[i];
            ++space;
        }
        if (t[i] == ' ') {
            space = i;
        }
    }
    t.resize(t.size() - 1);
    // cout << t.size();

    // step-2:
    string e, o; // even-odd
    for (int i = 0; i < t.size(); i++) {
        if (i % 2 == 0) { // even
            e.push_back(t[i]);
        } else { // odd
            o.push_back(t[i]);
        }
    }

    // stl-sort-cheat
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    // cout << e << " " << o;
    string t1;
    for (int i = 0; i < t.size(); i++) {
        if (i % 2 == 0) { // even
            t1.push_back(e[i / 2]);
        } else { // odd
            t1.push_back(o[i / 2]);
        }
    }
    // cout << t1 << endl;

    // step-3:
    for (int i = 0; i < t1.size(); i++) {
        if ((t1[i] >= '0' && t1[i] <= '9') ||
            (t1[i] >= 'A' && t1[i] <= 'F') ||
            (t1[i] >= 'a' && t1[i] <= 'f')) {
            char c = t1[i];
            if (c >= 'a' && c <= 'f') {
                c -= 32;
            }
            c = trans(c);
            cout << c;
        } else {
            cout << t1[i];
        }
    }

    return 0;
}
// Eqr v9oEb12U2ur4xu7rd931G1f50qDo
// 8084842CAE9B9G7D7BUFooqqrrrvuxu
// 64 位输出请用 printf("%lld")