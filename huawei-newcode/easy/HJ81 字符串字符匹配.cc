#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool helper(string s, string l) {
    set<char> sst(s.begin(), s.end()); // sst: short string set
    set<char> lst(l.begin(), l.end()); // lst: long string set
    for (auto it = sst.begin(); it != sst.end(); it++) {
        if (!lst.count(*it))
            return false;
    }
    return true;
}

int main() {
    string s;
    vector<string> v;
    while (getline(cin, s))
        v.push_back(s);

    int i = 0, j = 1;
    bool res = helper(v[i], v[j]);
    if (res) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}