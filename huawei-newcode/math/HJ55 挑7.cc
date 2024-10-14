#include <iostream>
#include <set>
using namespace std;

// brute-force-solution:(cheat)
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
        // cout << ": " << i << endl;
        if (!st.count(t)) {
            st.insert(t);
        }
    }

    for (int i = 0; i <= n; i++) {
        if (iss(i)) {
            if (st.count(i)) {
                continue;
            } else {
                st.insert(i);
                // cout << ": " << i << endl;
                ++r;
            }
        }
    }

    cout << r;
    return 0;
}
// 64 位输出请用 printf("%lld")