#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
50-20 20-5 + (10000) = 15000
50-10 10-5 + (1000) = 3500
*/

int main() {
    int n;
    // vector<vector<int>> v(n, vector<int>(2, 0)); // POE:
    vector<vector<int>> v;

    cin >> n;
    // cout << n << endl;
    int t;
    for (int i = 0; i < n; i++) {
        vector<int> o;
        for (int j = 0; j < 2; j++) {
            cin >> t;
            // v[i][j] = t; // POE: segment-fault
            o.push_back(t);
            // cout << t << " ";
        }
        v.push_back(o);
        // cout << endl;
    }

    string s;
    cin.ignore(256, '\n'); // POE: must-need-this
    getline(cin, s);
    // cout << s << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    stack<vector<int>> st;
    int count = 0; // count-upper-alpha
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            st.push(v[count]);
            ++count;
        } else if (s[i] == ')') {
            vector<int> a = st.top();
            st.pop();
            vector<int> b = st.top();
            st.pop();
            res += b[0] * b[1] * a[1]; // POE: reverse
            vector<int> c;
            c.push_back(b[0]);
            c.push_back(a[1]);
            // cout << "push: " << b[0] << " " << a[1] << endl;
            st.push(c);
        }
    }

    cout << res;
    return 0;
}
// 64 位输出请用 printf("%lld")