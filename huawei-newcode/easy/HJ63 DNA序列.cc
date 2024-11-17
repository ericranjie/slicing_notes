#include <iostream>
#include <map>
#include <vector>
using namespace std;

// stl-map-cheat-solution:
// need-reveal: cheat
int main() {
    string t;
    getline(cin, t);
    int n;
    cin >> n;
    map<int, vector<string>> mp;
    
    // Step-1: Sliding window;
    int l = 0, r = 0, c = 0; // l-r-c: left right counter
    for (int i = 0; i < t.size(); i++) {
        if (t[r] == 'G' || t[r] == 'C') ++c; // add counter
        if (r - l == n - 1) { // window match
            mp[c].push_back(t.substr(l, r - l + 1)); // POE: substr + 1
            ++r;
            if (t[l] == 'G' || t[l] == 'C') --c; // POE:
            ++l;
        } else if (r - l < n) { // window doesn't match
            ++r;
        } else if (r - l > n) { // window overflow
            if (t[l] == 'G' || t[l] == 'C') --c; // POE:
            ++l;
        }
    }

    auto it = mp.rbegin();
    if (it->second.size() > 0)
        cout << it->second[0] << endl;
    return 0;
}