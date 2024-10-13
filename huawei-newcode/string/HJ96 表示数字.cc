#include <iostream>
using namespace std;

int main() {
    string t, r;
    getline(cin, t);

    bool s = false; // start num recording
    int p = 0, c = 0;
    for (int i = 0; i < t.size(); i++) {

        if (t[i] >= '0' && t[i] <= '9') { // num char:
            // cout << "=" << t[i] << endl;
            c = i;
            if (!s) {
                string tmp = t.substr(p, c - p); // POE:
                // cout << "+ " << tmp << endl;
                r += tmp;
                s = true;
                p = c; // pre <- cur
            }
            if (i == t.size() - 1) {
                string tmp = t.substr(p, c - p + 1); // POE:
                // cout << "++ " << tmp << endl;
                tmp = "*" + tmp + "*";
                r += tmp;
            }
        } else { // alpha char:
        // cout << "alpha = " << t[i] << endl;
            c = i;
            if (s) {
                s = false;
                string tmp = t.substr(p, c - p);
                // cout << "- " << tmp << endl;
                tmp = "*" + tmp + "*";
                r += tmp;
                p = c;
            }
            if (i == t.size() - 1) {
                string tmp = t.substr(p, c - p + 1); // POE:
                // cout << "++ " << tmp << endl;
                r += tmp;
            }
            // r += t[c];
        }
    }

    cout << r;

    return 0;
}
// 64 位输出请用 printf("%lld")