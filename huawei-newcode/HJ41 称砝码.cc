#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
1 1 2
-> 1 2 3 4 0
*/

/*
7
58 18 139 163 57 167 178
1 1 3 2 6 3 4
*/

void recur(int n, int r, vector<int>& w, vector<int>& c,
           set<int>& st) {
    if (st.count(r)) {
        return;
    } else {
        st.insert(r);
    }

    for (int i = 0; i < n; i++) {
        if (c[i] >= 1) {
            // for (int j = 0; j < c[i]; j++) { // POE:
            r += w[i];
            --c[i];

            vector<int> tmp;
            for (auto it = st.begin(); it != st.end(); it++) {
                int t = *it + w[i];
                tmp.push_back(t);
            }

            for (int j = 0; j < tmp.size(); j++) {
                if (!st.count(tmp[j])) {
                    st.insert(tmp[j]);
                }
                cout << tmp[j] << " ";
            }

            recur(n, r, w, c, st);

            ++c[i];
            r -= w[i];
        }

    }

    return;
}

int main() {
    int n, t;
    vector<int> w;
    vector<int> c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        w.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        c.push_back(t);
    }

    set<int> st;
    int r = 0;
    recur(n, r, w, c, st);

    cout << st.size();

    return 0;
}