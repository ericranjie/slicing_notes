#include <iostream>
using namespace std;

// recite:special
// abandon:multiple-correct-answer
// b = a * p + r
// a / b =
//  a / a * p + r =
// 
//  1/(p+1) + (a-r)/(a*p + r)(p + 1)

void solve(string t) {
    int a = 0, b = 0, n = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '/') {
            a = n;
            // cout << "a = " << a << endl;
            n = 0;
            i++;
        }
        n *= 10;
        n += (t[i] - '0');
    }
    b = n;
    // cout << "b = " << n << endl;

    int d, m;

    while (true) {
        d = b / a;
        m = b % a;
        cout << "1/" << to_string(d + 1) << "+";
        int na = a - m;
        int nb = b * (d + 1);
        if (na == 1 || 
            (na > 1 && nb % na == 0)) {
            cout << to_string(na) << "/" << to_string(nb);
            break;
        } else {
            a = na;
            b = nb;
        }
    }
    cout << endl;
    return;
}

int main() {
    string t;
    while (getline(cin, t)) {
        // cout << t << endl;
        solve(t);
    }
    return 0;
}
// 64 位输出请用 printf("%lld")