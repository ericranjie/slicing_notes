#include <iostream>
using namespace std;

// need-reveal: complex
int main() {
    string t, r; // input target - result
    getline(cin, t);

    bool s = false; // s: start num recording
    int p = 0, c = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] >= '0' && t[i] <= '9') { // is number
            c = i; // c: current
            if (!s) {
                string tmp = t.substr(p, c - p); // POE:
                r += tmp;
                s = true; // start recording
                p = c; // pre <- current
            }
            if (i == t.size() - 1) {
                string tmp = t.substr(p, c - p + 1); // POE:
                tmp = "*" + tmp + "*";
                r += tmp;
            }
        } else { // is alpha
            c = i;
            if (s) {
                s = false; // reset: not recording
                string tmp = t.substr(p, c - p);
                tmp = "*" + tmp + "*";
                r += tmp;
                p = c;
            }
            if (i == t.size() - 1) {
                string tmp = t.substr(p, c - p + 1); // POE:
                r += tmp;
            }
        }
    }

    cout << r;
    return 0;
}