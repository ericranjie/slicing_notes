#include <iostream>
#include <vector>
using namespace std;

int main() {
    string t;
    getline(cin, t);
    vector<string> r;

    bool dq = false; // double quotation
    string o; // one parameter // POE:
    for (int i = 0; i < t.size(); i++) {
        char c = t[i]; // current char
        
        if (c == '\"') {
            if (!dq) {
                dq = true;
                continue; // jump this first "
            } else {
                dq = false;
                r.push_back(o);
                o.resize(0);
                continue;
            }
        }

        if (c == ' ') {
            if (dq) {
                o.push_back(c); // need this space
                continue; // jump
            } else {
                // cout << "= " << o << endl;
                if (o.size() > 0) { // POE:
                    r.push_back(o);
                    o.resize(0);
                }
                continue; // jump
            }
        }
        o.push_back(c);
        // cout << ": " << c << endl;
    }
    if (o.size() > 0) {
        r.push_back(o);
    }

    cout << r.size() << endl;
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")