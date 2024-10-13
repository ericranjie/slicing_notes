#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void re(stack<int> &st, int i, int n, vector<int> &in,
    vector<vector<int>> &res, vector<int> &one) {
    if (i > n && st.empty()) {
        res.push_back(one);
        // one.resize(0); // POE:
        return;
    }

    if (i <= n) {
        // one.push_back(r);
        st.push(in[i - 1]); ++i;

        re(st, i, n, in, res, one);
        
        --i;
        // one.pop_back();
        st.pop();
    }

    if (!st.empty()) {
        int t = st.top(); st.pop();
        one.push_back(t);

        re(st, i, n, in, res, one);

        one.pop_back(); st.push(t);        
    }
}

int main() {
    int n; vector<int> in;
    cin >> n;
    cin.ignore(256, '\n'); // POE:
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        in.push_back(t);
    }

    stack<int> st;
    vector<vector<int>> res;
    vector<int> one;

    re(st, 1, n, in, res, one);

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")