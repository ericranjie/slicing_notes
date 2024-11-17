#include <iostream>
#include <map>
using namespace std;

int main() {
    string r;
    getline(cin, r);
    int c[256] = {0};
    map<char, int> mp; // mp: map of character->index

    for (int i = 0; i < r.size(); i++) {
        ++c[r[i]];
        if (c[r[i]] >= 2) { // exist more than once
            if (mp.count(r[i])) mp.erase(r[i]);
            continue;
        } else { // exist only once
            if (!mp.count(r[i])) mp.insert({r[i], i});
        }
    }

    int mn = r.size() - 1; // mn: minimal index
    char res = r[mn];
    if (mp.size() == 0) {
        cout << "-1"; return 0;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (mn > it->second) res = it->first;
        mn = min(mn, it->second); // POE:
    }
    cout << res;
    return 0;
}