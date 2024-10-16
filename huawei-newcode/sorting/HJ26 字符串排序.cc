#include <iostream>
#include <map>
#include <vector>
using namespace std;

// stl-map-cheat-solution:
int main() {
    string t;
    getline(cin, t);

    map<char, vector<char>> mp;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] >= 'a' && t[i] <= 'z') {
            mp[t[i]].push_back(t[i]);
        } else if (t[i] >= 'A' && t[i] <= 'Z') {
            char c = (char)(t[i] + 32);
            mp[c].push_back(t[i]);
        }
    }

    string t1;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            t1.push_back(it->second[i]);
        }
    }
    // cout << t1 << endl;

    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        if ((t[i] >= 'a' && t[i] <= 'z') ||
            (t[i] >= 'A' && t[i] <= 'Z')) {
            cout << t1[j++];
        } else {
            cout << t[i];
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")