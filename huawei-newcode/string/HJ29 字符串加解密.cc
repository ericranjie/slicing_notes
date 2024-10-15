#include <iostream>
using namespace std;

int main() {
    string r, c;
    getline(cin, r);
    getline(cin, c);

    for (int i = 0; i < r.size(); i++) {
        if (r[i] >= '0' && r[i] <= '9') {
            r[i] = '0' + (((r[i] - '0') + 1) % 10);
        } else if (r[i] >= 'a' && r[i] <= 'z') {
            r[i] = 'A' + (((r[i] - 'a') + 1) % 26);
        } else if (r[i] >= 'A' && r[i] <= 'Z') {
            r[i] = 'a' + (((r[i] - 'A') + 1) % 26);
        }
    }
    cout << r << endl;
    
    r = c;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] >= '0' && r[i] <= '9') {
            r[i] = '0' + (((r[i] - '0') - 1 + 10) % 10);
        } else if (r[i] >= 'a' && r[i] <= 'z') {
            r[i] = 'A' + (((r[i] - 'a') - 1 + 26) % 26);
        } else if (r[i] >= 'A' && r[i] <= 'Z') {
            r[i] = 'a' + (((r[i] - 'A') - 1 + 26) % 26);
        }
    }
    cout << r << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")