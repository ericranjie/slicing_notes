#include <iostream>
using namespace std;

// need-reveal: ASCII singal;
int main() {
    string p;
    getline(cin, p);
    int res = 0;

    int l = p.length(), c = 0;
    if (l <= 4) res += 5;
    else if (l >= 5 && l <= 7) res += 10;
    else if (l >= 8) res += 25;

    bool lowa = false, higha = false;
    int num = 0, sig = 0;
    for (int i = 0; i < l; i++) {
        if (p[i] >= 'a' && p[i] <= 'z') lowa = true;
        if (p[i] >= 'A' && p[i] <= 'Z') higha = true;
        if (p[i] >= '0' && p[i] <= '9') ++num;
        if ((p[i] >= 0x21 && p[i] <= 0x2F) ||
            (p[i] >= 0x3A && p[i] <= 0x40) ||
            (p[i] >= 0x5B && p[i] <= 0x60) ||
            (p[i] >= 0x7B && p[i] <= 0x7E)) {
            ++sig;
        }
    }

    if (lowa && higha) res += 20;
    else if (lowa || higha) res += 10;

    if (num == 1) res += 10;
    else if (num > 1) res += 20;
    if (sig == 1) res += 10;
    else if (sig > 1) res += 25;
    
    if ((lowa && higha) && num && sig) res += 5;
    else if ((lowa || higha) && num && sig) res += 3;
    else if ((lowa || higha) && num) res += 2;


    if (res >= 90) cout << "VERY_SECURE";
    else if (res >= 80) cout << "SECURE";
    else if (res >= 70) cout << "VERY_STRONG";
    else if (res >= 60) cout << "STRONG";
    else if (res >= 50) cout << "AVERAGE";
    else if (res >= 25) cout << "WEAK";
    else if (res >= 0) cout << "VERY_WEAK";

    return 0;
}
// 64 位输出请用 printf("%lld")