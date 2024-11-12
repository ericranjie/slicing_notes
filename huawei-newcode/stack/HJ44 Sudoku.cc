#include <iostream>
#include <vector>
using namespace std;

bool veri(vector<vector<int>> &v, int i, int j, int t) { // verify
    for (int _i = 0; _i < 9; _i++) { // row-check
        if (v[_i][j] == t) {
            return false;
        }
    }

    for (int _j = 0; _j < 9; _j++) { // column-check
        if (v[i][_j] == t) {
            return false;
        }
    }

    int _i = i - i % 3;
    int _j = j - j % 3; // POE:
    for (int x = 0; x < 3; x++) { // cell-check
        for (int y = 0; y < 3; y++) {
            if (v[_i + x][_j + y] == t) {
                return false;
            }
        }
    }
    return true;
}

bool recu(vector<vector<int>> &v, int i, int j) { // recursive
    if (i == 9) {
        return true;
    }
    if (j >= 9) {
        return recu(v, i + 1, 0);
    }
    if (v[i][j] != 0) {
        return recu(v, i, j + 1);
    }
    // else-zero
    for (int k = 1; k <= 9; k++) {
        if (veri(v, i, j, k) == false) {
            continue;
        }
        v[i][j] = k;
        if (recu(v, i, j + 1)) {
            return true;
        }
        v[i][j] = 0;
    }

    return false;
}

int main() {
    vector<vector<int>> v(9, vector<int>(9, 0));
    int t;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> t;
            v[i][j] = t;
        }
    }
    
    bool res = recu(v, 0, 0);
    if (res) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")