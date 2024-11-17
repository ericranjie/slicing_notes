#include <iostream>
#include <vector>
using namespace std;

// need-recite: BFS template;
void helper(int i, int j, int m, int n, vector<vector<int>>& v,
            vector<vector<int>>& one,
            vector<vector<int>>& res) {
    if (i == m - 1 && j == n - 1) { // Guard: BFS come to end;
        res = one;
        return; // success
    }
    if (j < n - 1 && v[i][j + 1] == 0) {
        one.push_back({i, j + 1});
        v[i][j] = 1;
        helper(i, j + 1, m, n, v, one, res);
        v[i][j] = 0;
        one.pop_back();
    }
    if (j > 0 && v[i][j - 1] == 0) {
        one.push_back({i, j - 1});
        v[i][j] = 1;
        helper(i, j - 1, m, n, v, one, res);
        v[i][j] = 0;
        one.pop_back();
    }
    if (i < m - 1 && v[i + 1][j] == 0) {
        one.push_back({i + 1, j});
        v[i][j] = 1;
        helper(i + 1, j, m, n, v, one, res);
        v[i][j] = 0;
        one.pop_back();
    }
    if (i > 0 && v[i - 1][j] == 0) {
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

    // Step-1: Input;
    char t;
    for (int i = 0; i < m; i++) {
        vector<int> o;
        for (int j = 0; j < n; j++) {
            cin >> t;
            o.push_back(t - '0'); // character into one-line
        }
        v.push_back(o); // one-line push into 2d-vector
    }


    // Step-2: Start BFS recursive;
    vector<vector<int>> one;
    vector<vector<int>> res;
    one.push_back({0, 0});
    helper(0, 0, m, n, v, one, res);

    for (int i = 0; i < res.size(); i++)
        cout << "(" << res[i][0] << "," << res[i][1] << ")" << endl;
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