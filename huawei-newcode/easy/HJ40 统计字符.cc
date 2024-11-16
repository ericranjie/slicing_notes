#include <iostream>
using namespace std;

int main() {
    string raw;
    getline(cin, raw);
    int a = 0, s = 0, n = 0, o = 0;

    for (auto it = raw.begin(); it != raw.end(); it++) {
        if ((*it >= 'a' && *it <= 'z') ||
            (*it >= 'A' && *it <= 'Z')) {
            a++;
        } else if (*it == ' ') {
            s++;
        } else if (*it >= '0' && *it <= '9') {
            n++;
        } else o++;
    }

    cout << a << endl;
    cout << s << endl;
    cout << n << endl;
    cout << o << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")