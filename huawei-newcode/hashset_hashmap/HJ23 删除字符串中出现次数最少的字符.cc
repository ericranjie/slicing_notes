#include <iostream>
#include <vector>
using namespace std;

// not-hash-solution:
int main() {
    string t;
    getline(cin, t);

    int mp[128] = {0};
    for (int i = 0; i < t.size(); i++) {
        ++mp[t[i]];
    }

    vector<vector<int>> b(20, vector<int>(0, 0));
    for (int i = 0; i < 128; i++) {
        // if (mp[i] > 0) {
        // }
        b[mp[i]].push_back(i);
    }

    int i = 1;
    for (i = 1; i <= 20; i++) {
        if (b[i].size() > 0) {
            // for (int j = 0; j < b[i].size(); j++) {
            //     // cout << i << " " << b[i][j] << endl;
            // }
            break;
        }
    }

    vector<int> d = b[i];
    bool c = false;
    for (int j = 0; j < t.size(); j++) {
        for (int k = 0; k < d.size(); k++) {
            if (t[j] == d[k]) {
                // cout << endl << "c: " << t[j] << endl;
                c = true;
            }
        }
        if (c) {
            c = false;
            continue;
        } else {
            cout << t[j];
            c = false;
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")