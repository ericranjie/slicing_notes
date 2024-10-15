#include <iostream>
#include <vector>
using namespace std;

void trans(string t) {
    if (t.size() <= 2) {
        cout << "0" << endl;
        return;
    }

    int l = 0, r = 0;
    for (int i = 2; i < t.size(); i++) {
        char c = t[i];
        int m = 0;
        if (c >= '0' && c <= '9') { // num
            m = (c - '0');
        } else if (c >= 'A' && c <= 'F') { // POE: not E
            m = (c - 'A' + 10);
        }
        
        // cout << "-" << m << endl;

        int j = 1, k = t.size() - i - 1; // POE:
        while (k-- > 0) {
            j *= 16;
        }
        m = m * j;
        r += m;

        // cout << "--" << r << endl;
        ++l;
    }

    cout << r << endl;
    return;
}

int main() {
    string t;
    vector<string> v;
    while (getline(cin, t)) {
        v.push_back(t);
        trans(t);
        // cout << t << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")