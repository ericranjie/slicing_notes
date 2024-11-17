#include <iostream>
#include <set>
using namespace std;

// brute-force-solution:(cheat)
// need-reveal:
bool iss(int a) {
    while (a >= 1) {
        int m = a % 10;
        if (m == 7) return true;
        a = a / 10;
    }

    return false;
}

int main() {
    int n, r = 0;
    cin >> n;
    set<int> st;

    for (int i = 1; i * 7 <= n; i++) {
        int t = i * 7;
        ++r;
        if (!st.count(t))
            st.insert(t);
    }

    for (int i = 0; i <= n; i++) {
        if (iss(i)) {
            if (st.count(i)) {
                continue;
            } else {
                st.insert(i);
                ++r;
            }
        }
    }
    cout << r;
    return 0;
}