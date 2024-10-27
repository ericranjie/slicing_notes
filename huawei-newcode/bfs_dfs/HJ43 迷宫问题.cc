#include <iostream>
#include <vector>
using namespace std;

void helper(int i, int j, int m, int n, vector<vector<int>>& v,
            vector<vector<int>>& one,
            vector<vector<int>>& res) {
    // cout << i << " " << j << " <- ";
    if (i == m - 1 && j == n - 1) {
        // cout << "f1" << endl;
        res = one;
        return; // success
    }
#if 0
    else if (i == m - 1 && j < n - 1) { // last-row-block
        if (v[i][j + 1] == 1 && v[i - 1][j] == 1) {
            // cout << "f2" << endl;
            return; // failed
        } else {
            if (v[i][j + 1] == 0) {
                one.push_back({i, j + 1});
                v[i][j + 1] = 1;
                helper(i, j + 1, m, n, v, one, res);
                v[i][j + 1] = 0;
                one.pop_back();
            } else if (v[i - 1][j] == 0) {
                one.push_back({i - 1, j});
                v[i - 1][j] = 1;
                helper(i - 1, j, m, n, v, one, res);
                v[i - 1][j] = 0;
                one.pop_back();
            }
        }
    } else if (j == n - 1 && i < m - 1) {
        if (v[i + 1][j] == 1 && v[i][j - 1] == 1) { // last-column-block
            // cout << "f3" << endl;
            return; // failed
        } else {
            if (v[i + 1][j] == 0) {
                one.push_back({i + 1, j});
                v[i + 1][j] = 1;
                helper(i + 1, j, m, n, v, one, res);
                v[i + 1][j] = 0;
                one.pop_back();
            } else if (v[i][j - 1] == 0) {
                one.push_back({i, j - 1});
                v[i][j - 1] = 1;
                helper(i, j - 1, m, n, v, one, res);
                v[i][j - 1] = 0;
                one.pop_back();
            }
        }
    } else if (i > 0 && i < m - 1 &&
               j > 0 && j < n - 1) {
        if (v[i][j + 1] == 1 && v[i + 1][j] == 1 &&
                v[i][j - 1] == 1 && v[i - 1][j] == 1) {
            // cout << "f4" << endl;
            return; // failed
        }
        // POE:
        if (v[i + 1][j] == 0) {
            one.push_back({i + 1, j});
            helper(i + 1, j, m, n, v, one, res);
            one.pop_back();
        }
        if (v[i][j + 1] == 0) {
            one.push_back({i, j + 1});
            helper(i, j + 1, m, n, v, one, res);
            one.pop_back();
        }
    }
#endif
    if (j < n - 1 &&
        v[i][j + 1] == 0) {
        one.push_back({i, j + 1});
        v[i][j] = 1;
        helper(i, j + 1, m, n, v, one, res);
        v[i][j] = 0;
        one.pop_back();
    }
    if (j > 0 &&
        v[i][j - 1] == 0) {
        one.push_back({i, j - 1});
        v[i][j] = 1;
        helper(i, j - 1, m, n, v, one, res);
        v[i][j] = 0;
        one.pop_back();
    }
    if (i < m - 1 &&
        v[i + 1][j] == 0) {
        one.push_back({i + 1, j});
        v[i][j] = 1;
        helper(i + 1, j, m, n, v, one, res);
        v[i][j] = 0;
        one.pop_back();
    }
    if (i > 0 &&
        v[i - 1][j] == 0) {
        one.push_back({i - 1, j});
        v[i][j] = 1;
        helper(i - 1, j, m, n, v, one, res);
        v[i][j] = 0;
        one.pop_back();
    }

    return;
}

int main() {
    int m, n;
    vector<vector<int>> v;
    cin >> m;
    cin >> n;
    cin.ignore(256, '\n'); // POE:

    char t;
    for (int i = 0; i < m; i++) {
        vector<int> o;
        for (int j = 0; j < n; j++) {
            cin >> t;
            o.push_back(t - '0');
            // cout << t << " ";
        }
        v.push_back(o);
        // cout << endl;
    }

    vector<vector<int>> one;
    vector<vector<int>> res;
    one.push_back({0, 0});
    helper(0, 0, m, n, v, one, res);

    for (int i = 0; i < res.size(); i++) {
        cout << "(" << res[i][0] << "," << res[i][1] << ")" << endl;
    }

    // cout << res.size() << endl;

    return 0;
}

// 3 2
// 0 1
// 0 1
// 0 0

// 4 6
// 0 0 1 1 1 1
// 1 0 1 0 0 0
// 1 0 0 0 1 0
// 1 1 1 1 0 0

// (0,0)
// (0,1)
// (1,1)
// (2,1)
// (2,2)
// (2,3)
// (1,3)
// (1,4)
// (1,5)
// (2,5)
// (3,5)

// 5 5
// 0 1 0 0 0
// 0 1 0 1 0
// 0 0 0 0 1
// 0 1 1 1 0
// 0 0 0 0 0

// (0,0)
// (1,0)
// (2,0)
// (3,0)
// (4,0)
// (4,1)
// (4,2)
// (4,3)
// (4,4)

// 64 位输出请用 printf("%lld")