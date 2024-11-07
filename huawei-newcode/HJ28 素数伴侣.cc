#include <iostream>
#include <vector>
using namespace std;

// TLE-Solution:no-memo-and-memo 22/24
// abandon: or-optimize-or-find-new-solution
bool is_prime(int p);
bool find(int oi, vector<int> &even, vector<bool> visit,
    vector<int> &match, vector<vector<bool>> &memo);

// recite-all:
//   1. hungarian-algorithm;
//   2. is-prime;

int main() {
    int n;
    cin >> n;
    int t;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        cin >> t; 
        if (t % 2 == 0) {
            even.push_back(t);
        } else {
            odd.push_back(t);
        }
    }

    if (odd.size() == 0 || even.size() == 0) { // POE:
        cout << 0;
        return 0;
    }

    vector<vector<bool>> memo(even.size(),
        vector<bool>(odd.size(), false));
    for (int i = 0; i < even.size(); ++i) {
        for (int j = 0; j < odd.size(); ++j) {
            if (is_prime(even[i] + odd[j])) {
                memo[i][j] = true;
            }
        }
    }

    int res = 0;
    vector<int> match(even.size(), -1); // POE:-1
    for (int i = 0; i < odd.size(); i++) {
        vector<bool> visit(even.size(), false); // visited-bitmap
        if (find(i, even, visit, match, memo)) {
            ++res;
        }
    }

    cout << res << endl;
    return 0;
}

bool find(int oi, vector<int> &even, vector<bool> visit,
    vector<int> &match, vector<vector<bool>> &memo) {
    for (int i = 0; i < even.size(); i++) {
        if (memo[i][oi] && !visit[i]) {
            visit[i] = true;
            if (match[i] == -1 ||
                find(match[i], even, visit, match, memo)) {
                match[i] = oi;
                return true;
            }
        }
    }
    return false;
}

bool is_prime(int p) {
    for (int i = 2; i * i <= p; i++) { // POE:must-have-equal
        if (p % i == 0) { // POE:is-mod-not-divide
            // cout << "false: " << p << " " << i << endl;
            return false; // POE:not-prime
        }
    }
    return true; // is-prime
}

// 4
// 4 6 5 11

// 2
// 3 6

// 74
// 8087 27923 19092 18651 1579 18356 21974 8081 15714 27208 25264 25435 17365 3945 25503 16383 19618 7751 5924 20474 1391 27361 27910 4011 11140 7997 5387 9937 19614 7118 21667 13881 29124 3590 10568 7137 19805 15450 9559 25368 18942 3632 7291 18194 18561 17701 29019 26510 28630 10646 21725 25013 89 2683 17839 23808 3076 16607 21840 1113 15895 1621 15623 1111 22682 17203 16150 8928 26537 18635 17326 16178 981 28991

// 64 位输出请用 printf("%lld")