#include <iostream>
#include <vector>
#include <set>
using namespace std;

// cheat-solution:
int main() {
    int n;
    cin >> n;

    int t;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
        // cout << t << " ";
    }

    set<int> st(v.begin(), v.end());
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")