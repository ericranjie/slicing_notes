#include <iostream>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    // cout << a << " " << b << endl;

    int n = min(a.size(), b.size());

    string r;
    int c = 0; // carry
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (n > 0) {
        int na = a[i] - '0';
        int nb = b[j] - '0';
        int o = na + nb + c;
        // cout << o << na << nb << " ";
        if (o >= 10) {
            c = 1;
            o -= 10;
        } else {
            c = 0;
        }

        r = to_string(o) + r;

        --i;
        --j;
        --n;
    }

    if (a.size() > b.size()) {
        for (int k = a.size() - b.size() - 1; k >= 0; k--) {
            int na = a[k] - '0';
            int o = na + c;
            if (o >= 10) {
                c = 1;
                o -= 10;
            } else {
                c = 0;
            }
            r = to_string(o) + r;
        }
    } else if (a.size() < b.size()) {
        for (int k = b.size() - a.size() - 1; k >= 0; k--) {
            int nb = b[k] - '0';
            int o = nb + c;
            if (o >= 10) {
                c = 1;
                o -= 10;
            } else {
                c = 0;
            }
            r = to_string(o) + r;
        }
    }
    if (c == 1) {
        r = "1" + r;
    }


    cout << r;

    return 0;
}
// 64 位输出请用 printf("%lld")