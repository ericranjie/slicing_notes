#include <iostream>
#include <vector>
using namespace std;

// not-hash-solution:
// need-reveal: confuse
int main() {
    string t;
    getline(cin, t);

    // Step-1: Statistic character's count number;
    int mp[128] = {0}; // mp: map of character -> number
    for (int i = 0; i < t.size(); i++)
        ++mp[t[i]];

    vector<vector<int>> b(20, vector<int>(0, 0));
    for (int i = 0; i < 128; i++)
        b[mp[i]].push_back(i); // b: number -> character index

    int i = 1;
    for (i = 1; i <= 20; i++)
        if (b[i].size() > 0) break;

    vector<int> d = b[i];
    bool c = false;
    for (int j = 0; j < t.size(); j++) {
        for (int k = 0; k < d.size(); k++)
            if (t[j] == d[k])
                c = true;
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