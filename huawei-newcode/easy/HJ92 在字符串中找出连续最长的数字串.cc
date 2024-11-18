#include <iostream>
#include <vector>
#include <map>
using namespace std;

void helper(string t) {
    map<int, vector<string>> mp; // mp: map of length -> string
    bool s = false;
    int p = 0, c = 0, mx = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] >= '0' && t[i] <= '9') { // is number
            c = i;
            if (!s)
                p = i;
            if (i == t.size() - 1) { // POE:
                mx = max(mx, i - p + 1);
                string tmp = t.substr(p, c - p + 1);
                mp[i - p + 1].push_back(tmp);
            }
            s = true;
        } else { // is alpha
            if (s) {
                int l = c - p + 1;
                mx = max(mx, l);
                string tmp = t.substr(p, c - p + 1); // POE:
                mp[l].push_back(tmp);
            }
            p = i;
            s = false;
        }
    }
    vector<string> tmp = mp.rbegin()->second;
    for (int i = 0; i < tmp.size(); i++)
        cout << tmp[i];
    cout << "," << mx << endl;
}

int main() {
    string t;
    vector<string> v;

    while (getline(cin, t)) {
        v.push_back(t);
        helper(t);
    }
    return 0;
}