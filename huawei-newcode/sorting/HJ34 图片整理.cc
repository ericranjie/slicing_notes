#include <iostream>
using namespace std;

// bucket-sort:
int main() {
    string t;
    getline(cin, t);
    char c[128] = {0};

    for (int i = 0; i < t.size(); i++) {
        ++c[t[i]];
    }
    for (int i = 0; i < 128; i++) {
        if (c[i] == 0) { 
            continue;
        }
        while (c[i] > 0) {
            cout << (char)i;
            --c[i];
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")