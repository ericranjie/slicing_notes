#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool helper(string s, string l) {
    bool res = true;
    set<char> sst(s.begin(), s.end());
    set<char> lst(l.begin(), l.end());
    for (auto it = sst.begin(); it != sst.end(); it++) {
        if (!lst.count(*it)) {
            res = false;
            return res;
        }
    }
    return res;
}

int main() {
    string s;
    vector<string> v;
    while (getline(cin, s))
        v.push_back(s);

    int i = 0, j = 1;
    while (i < v.size() && j < v.size()) {
        bool res = helper(v[i], v[j]);
        if (res) cout << "true" << endl;
        else cout << "false" << endl;
        ++i; ++j;
    }
    return 0;
}