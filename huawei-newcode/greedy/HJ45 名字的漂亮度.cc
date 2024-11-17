#include <iostream>
#include <vector>
#include <map>
using namespace std;

// stl-map-cheat-solution:
void helper(string t) {
    map<int, vector<char>> mp; // POE:
    int c[26] = {0};

    for (int i = 0; i < t.size(); i++) {
        int id = t[i] - 'a';
        ++c[id];
    }

    for (int i = 0; i < 26; i++) {
        if (c[i] != 0) {
            mp[c[i]].push_back((char)(i + 'a'));
        }
    }

    int r = 0, l = 26;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        for (int j = 0; j < it->second.size(); j++) {
            r += (l * it->first);
            --l;
        }
        // --l; // POE
    }
    cout << r << endl;

    return;
}

int main() {
    vector<string> v;
    int n;

    cin >> n;
    cin.ignore(256, '\n');

    for (int i = 0; i < n; i++) {
        string t;
        getline(cin, t);
        v.push_back(t);
        helper(t);
    }

    return 0;
}