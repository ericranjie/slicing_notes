#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

// std-cheat-solution: sort
int main() {
    string r;
    getline(cin, r);

    // int b[1000] = {0};
    vector<vector<int>> b(1000); // bucket
    int c[128] = {0}; // POE:

    for (int i = 0; i < r.size(); i++) {
        c[r[i]] += 1;
    }

    for (int i = 0; i < 128; i++) {
        if (c[i] != 0)
        b[c[i]].push_back(i);
        // if (c[i] != 0) cout << i << "-" << c[i] << endl;
    }

    for (int i = 999; i >= 0; i--) {
        if (b[i].size()) sort(b[i].begin(), b[i].end());
        for (int j = 0; j < b[i].size(); j++) {
            cout << (char)b[i][j];
        }
    }

    return 0;
}

#if 0
int main() {
    string raw;
    getline(cin, raw);

    map<char, int> mp;
    for (auto it = raw.begin(); it != raw.end(); it++) {
        if (!mp.count(*it)) {
            mp.insert({*it, 1});
        } else {
            mp[*it]++;
        }
    }

    int p = 0; bool start = false;
    auto l = mp.rbegin(), r = mp.rbegin();
    vector<char> v;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        
        if (p == it->first) {
            start = true;
            v.push_back(it->first);
            r = it;
            continue;
        } else {
            start = false;
            sort(v.begin(), v.end());
            for (auto i = v.begin(); i != v.end(); i++) {
                cout << *i;
            }
            v.resize(0);
        }
        cout << it->first;
        p = it->first;
        if (start == false)
            l = it;
    }
    return 0;
}
#endif
// 64 位输出请用 printf("%lld")