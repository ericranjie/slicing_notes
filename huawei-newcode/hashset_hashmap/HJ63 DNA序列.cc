#include <iostream>
#include <map>
#include <vector>
using namespace std;

// stl-map-cheat-solution:
int main() {
    string t;
    getline(cin, t);
    int n;
    cin >> n;

    map<int, vector<string>> mp;
    
    int l = 0, r = 0, c = 0; // left-right-counter
    for (int i = 0; i < t.size(); i++) {
        // if (t[i] == 'G' || t[i] == 'C') {
        //     ++c;
        // }
        // ++r;
        // if (r >= t.size()) {
        //     break;
        // }
        if (t[r] == 'G' || t[r] == 'C') {
            ++c;
        }
        if (r - l == n - 1) {
            mp[c].push_back(t.substr(l, r - l + 1)); // POE: substr + 1
            // cout << c << " - " << t.substr(l, r - l + 1) << endl;
            ++r;
            if (t[l] == 'G' || t[l] == 'C') { // POE:
                --c;
            }
            ++l;
        } else if (r - l < n) {
            ++r;
        } else if (r - l > n) {
            if (t[l] == 'G' || t[l] == 'C') { // POE:
                --c;
            }
            ++l;
        }
    }

    // for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    //     for (int i = 0; i < it->second.size(); i++) {
    //         cout << it->first << " " << it->second[i] << endl;
    //     }
    // }
    auto it = mp.rbegin();
    if (it->second.size() > 0) {
        cout << it->second[0] << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")