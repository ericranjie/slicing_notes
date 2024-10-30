#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
using namespace std;

// 15 123 456 786 453 46 7 5 3 665 453456 745 456 786 453 123
// 5 6 3 6 3 0
// 30 ;3 6: 0 123 3 453 7 3 9 453456 13 453 14 123; 6 7: 1 456 2 786 4 46 8 665 9 453456 11 456 12 786;

int main() {
    int ni, nr;
    int t;
    vector<int> vi, vr;

    cin >> ni;
    for (int i = 0; i < ni; i++) {
        cin >> t;
        vi.push_back(t);
        // cout << t << " ";
    }
    // cout << endl;
    cin >> nr;
    for (int i = 0; i < nr; i++) {
        cin >> t;
        vr.push_back(t);
        // cout << t << " ";
    }
    // cout << endl;

    string res;
    set<int> st(vr.begin(), vr.end());
    int all = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
        // cout << *it << " ";
        int c = 0; // current-count
        string l; // currnet-level
        string needle = to_string(*it); // currnet-needle-string
        // cout << "needle: " << needle << endl;
        for (int i = 0; i < vi.size(); i++) {
            string tmp = to_string(vi[i]);
            // if (tmp.find_first_of(needle) != tmp.npos) {
            if (strstr(tmp.c_str(), needle.c_str()) != nullptr) { // POE:
                // cout << "tmp: " << tmp << " " << needle << endl;
                l += to_string(i);
                l += " ";
                l += tmp;
                l += " ";
                ++c;
            }
        }
        if (c > 0) {
            l = needle + " " + to_string(c) + " " + l;
            res += l;
            // cout << l << endl;
            l.resize(0);
            all += c * 2;
            all += 2;
        }
    }

    res = to_string(all) + " " + res;

    cout << res;

    return 0;
}
// 7 6396 4598 8539 6047 2019 11269 7402
// 3 16 4 26
// 12 4 3 1 4598 3 6047 6 7402 26 1 5 11269 


// 64 位输出请用 printf("%lld")