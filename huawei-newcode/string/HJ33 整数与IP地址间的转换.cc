#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    string t;
    int d, r = 0;
    getline(cin, t);
    cin >> d;

    string o;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != '.') {
            o.push_back(t[i]);
        } else {
            v.push_back(o);
            o.resize(0);
            continue;
        }
    }

    // transfer to 2bit
    string t1;
    int dex[4];
    v.push_back(o);
    for (int i = 0; i < v.size(); i++) {
        // cout << v[i] << endl;
        o = v[i];
        for (int j = 0; j < o.size(); j++) {
            char c = o[j];

        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")