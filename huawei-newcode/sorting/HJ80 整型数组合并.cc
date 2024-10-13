#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#if 0
void quicksort(vector<int> *r, int s, int e) {
    int p = (*r)[e], l = s - 1, h = e;

    if (s < e) {
    for (int i = s; i < e; i++) {
        if ((*r)[i] <= p) {
            ++l;
            int t = (*r)[l];
            (*r)[l] = (*r)[i];
            (*r)[i] = t;
        }
    }
    (*r)[e] = (*r)[l + 1];
    (*r)[l + 1] = p;
    quicksort(r, s, p - 1);
    quicksort(r, p + 1, e);
    }
}
#endif

int main() {
    int a, b, c;
    vector<int> m, n;
    set<int> st;

    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> c;
        m.push_back(c);
        // cout << c;
    }

    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> c;
        n.push_back(c);
        // cout << c;
    }

    // quicksort(&m, 0, a);
    sort(m.begin(), m.end());
    sort(n.begin(), n.end());
    // for (int i = 0; i < a; i++) {
    //     cout << m[i];
    // }

    int i = 0, j = 0, p = 0;
    while (i < a && j < b) {
        if (m[i] > n[j]) {
            if (n[j] == p) { ++j; continue; } // POE:
            cout << n[j]; p = n[j];
            ++j;
        } else if (m[i] < n[j]) {
            if (m[i] == p) { ++i; continue; }
            cout << m[i]; p = m[i];
            ++i;
        } else {
            cout << m[i]; p = m[i];
            ++i; ++j;
        }
    }

    if (i >= a) {
        for (j; j < b; j++) cout << n[j];
    } else if (j >= b) {
        for (i; i < a; i++) cout << m[i];
    }

    return 0;
}
// 64 位输出请用 printf("%lld")