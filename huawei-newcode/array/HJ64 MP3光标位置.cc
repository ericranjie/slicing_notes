#include <iostream>
using namespace std;

int main() {
    int n; // number-of-music
    string t; // command-sequence
    
    // step-0: input
    cin >> n;
    cin.ignore(256, '\n'); // POE:
    getline(cin, t);
    // cout << n;
    // cout << t;

    // step-1: define-window
    int l = 0, r = 0; // window-left-right-bounder
    bool w = false; // window-exist
    if (n <= 4) {
        l = 0;
        r = n - 1; // POE: must-(-1)
        w = false; // window-doesnot-exist
    } else {
        l = 0;
        r = 3; // POE: not-4
        w = true; // window-exist
    }

    // step-2: start-moving
    int p = 0; // present
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'U') { // up
            if (p == l && p != 0 && w) { // left-bound
                --l;
                --r;
                --p;
            } else if (p == 0) { // up-to-zero
                p = n - 1; // present-change-to-(n-1)
                if (w) { // window-exist
                    r = n - 1;
                    l = n - 4;
                }
            } else {
                --p;
            }
            // cout << "U: " << p << l << r << endl;
        } else if (t[i] == 'D') { // down
            if (p == r && p != n - 1 && w) { // right-bound
                ++l;
                ++r;
                ++p;
            } else if (p == n - 1) { // down-to-(n-1)
                p = 0; // present-change-to-zero
                if (w) {
                    r = 3;
                    l = 0;
                }
            } else {
                ++p;
            }
            // cout << "D: " << p << l << r << endl;
        }
    }

    for (int i = l; i <= r; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << p + 1;

    return 0;
}
// 2
// DUDUDDUUDUDDDDUDUDDDUUDDUDDUDUDUDDDUDUDUUDDUUDDUUUDUDUUUDDUDUDDUUDUDDDDUDUDUUDUDDDDDUU
// 64 位输出请用 printf("%lld")