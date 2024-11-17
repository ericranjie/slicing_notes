#include <iostream>
#include <vector>
#include <set>
using namespace std;

// need-familiar: math;
int main() {
    int a;
    cin >> a;
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 34; j++) {
            for (int k = 0; k < 101; k += 3) {
                if ((i * 5 + j * 3 + k / 3) == 100 &&
                    (i + j + k) == 100) {
                    cout << i << " " << j << " " << k << endl;
                } 
            }
        }
    }
    return 0;
}

#if 0
int main() {
    int a;
    cin >> a;
    vector<vector<int>> res;
    int dp[101][101] = {0};

    dp[5][1] = 1;
    dp[3][1] = 1;
    dp[1][3] = 1;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (i > 5 &&
                dp[i - 5][j - 1] == 1) {
                
            }
        }
    }

    return 0;
}
#endif

#if 0
void re(int m, int c, vector<vector<int>> &res,
    vector<int> &o, set<set<int>> &st) {
    
    if (c > 100 || m < 0) return;
    if (o[0] > 20 || o[1] > 34) return;
    else if (c == 100 && m == 0) {
        set<int> t;
        t.insert(o[0]); t.insert(o[1]); t.insert(o[2]);
        if (st.count(t)) { return; }
        else { st.insert(t); }
        cout << m << " " << c << endl;
        cout << o[0] << " " << o[1] << " " << o[2] << " " << endl; 
        res.push_back(o);
        return;
    }

    o[2] += 3;
    re(m - 1, c + 3, res, o, st);
    o[2] -= 3;

    o[1] += 1;
    re(m - 3, c + 1, res, o, st);
    o[1] -= 1;

    o[0] += 1;
    re(m - 5, c + 1, res, o, st);
    o[0] -= 1;

    return;
}

int main() {
    int a;
    cin >> a;
    vector<vector<int>> res;
    vector<int> o(3, 0);
    set<set<int>> st;

    re(100, 0, res, o, st);

    return 0;
}
#endif
#if 0
m c
1 3
3 1
5 1
#endif