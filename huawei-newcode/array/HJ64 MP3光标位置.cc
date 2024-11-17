#include <iostream>
using namespace std;

int main() {
    int n; // n: number of music
    string t; // t: command sequence
    
    // Step-0: Input;
    cin >> n;
    cin.ignore(256, '\n'); // POE:
    getline(cin, t);

    // Step-1: Define window;
    int l = 0, r = 0; // l-r: window's left right bounder
    bool w = false; // w: window exist
    if (n <= 4) {
        l = 0;
        r = n - 1; // POE: must-(-1)
        w = false; // window doesn't exist
    } else {
        l = 0;
        r = 3; // POE: not-4
        w = true; // window exist
    }

    // Step-2: Start moving;
    int p = 0; // p: present
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