#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// TreeMap-Solution:
int main() {
    int nc, nv, ni = 0; // nc-nv-ni: num of candidate, vote, invalidate
    vector<string> c, v; // c-v: candidates, votes,
    map<string, int> mp; // mp: map of string -> count number

    // Step-1: Input;
    cin >> nc;
    for (int i = 0; i < nc; i++) {
        string t;
        cin >> t;
        c.push_back(t);
    }
    cin >> nv;
    for (int i = 0; i < nv; i++) {
        string t;
        cin >> t;
        v.push_back(t);
    }

    // Step-2: Init candidate set;
    set<string> st(c.begin(), c.end());
    for (auto it = st.begin(); it != st.end(); it++) {
        mp[*it] = 0;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!mp.count(v[i])) {
            if (!st.count(v[i])) {
                ni++;
                continue;
            }
            mp[v[i]] = 1;
        } else
            ++mp[v[i]];
    }

    for (auto it = c.begin(); it != c.end(); it++) // POE:
        cout << *it << " : "<< mp[*it] << endl;
    cout << "Invalid : " << ni;
    return 0;
}