#include <iostream>
#include <algorithm>
using namespace std;

// Translate: 16 to 2 and reverse;
// Must be uppercase;
char trans(char c) { 
    int d = 0; // decimal
    if (c >= '0' && c <= '9') d = c - '0';
    else if (c >= 'A' && c <= 'F') d = (c - 'A') + 10;

    int r = 0, l = 8; // reverse-and-level
    while (d > 0) {
        int i = d % 2;
        r += (i * l);

        l /= 2;
        d = d >> 1;
    }

    if (r >= 0 && r <= 9) return (char)('0' + r);
    else if (r >= 10 && r <= 15)
        return (char)('A' + (r - 10));

    return c; // error
}

int main() {
    string t;
    getline(cin, t);

    // Step-1: Merge string;
    int space = 0;
    for (int i = 0; i < t.size(); i++) {
        if (space > 0) {
            t[space] = t[i];
            ++space;
        }
        if (t[i] == ' ') space = i;
    }
    t.resize(t.size() - 1);

    // Step-2.1: Extract and sort;
    string e, o; // even-and-odd
    for (int i = 0; i < t.size(); i++)
        if (i % 2 == 0) 
            e.push_back(t[i]);
        else
            o.push_back(t[i]);

    // STL-sort-cheat: Need reveal;
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());

    // Step-2.2: Push into original string;
    string t1; // new-target-string
    for (int i = 0; i < t.size(); i++)
        if (i % 2 == 0)
            t1.push_back(e[i / 2]);
        else
            t1.push_back(o[i / 2]);

    // Step-3: 16-to-2 reverse translation;
    for (int i = 0; i < t1.size(); i++) {
        if ((t1[i] >= '0' && t1[i] <= '9') ||
            (t1[i] >= 'A' && t1[i] <= 'F') ||
            (t1[i] >= 'a' && t1[i] <= 'f')) {
            char c = t1[i];
            if (c >= 'a' && c <= 'f') { // trans-to-upper
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