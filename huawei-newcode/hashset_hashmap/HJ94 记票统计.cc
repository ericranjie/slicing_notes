#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int nc, nv, ni = 0;
    vector<string> c, v;
    map<string, int> mp;
    

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

    set<string> st(c.begin(), c.end());

    for (auto it = st.begin(); it != st.end(); it++) {
        mp[*it] = 0;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!mp.count(v[i])) {
            // mp.insert(v[i]);
            if (!st.count(v[i])) {
                ni++;
                continue;
            }
            mp[v[i]] = 1;
        } else {
            ++mp[v[i]];
        }
    }

    for (auto it = c.begin(); it != c.end(); it++) {
        cout << *it << " : "<< mp[*it] << endl;
    } // POE:

    // for (auto it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->first << " : "<< it->second << endl;
    // }
    cout << "Invalid : " << ni;

    return 0;
}
// 64 位输出请用 printf("%lld")