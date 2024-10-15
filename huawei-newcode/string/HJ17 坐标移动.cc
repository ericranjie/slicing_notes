#include <iostream>
using namespace std;

bool valid(string r) {
    if (r.size() <= 1) {
        // cout << "v1" << endl;
        return false;
    }
    int i = 0;
    if (r[i] < 'A' || r[i] > 'Z') {
        // cout << "v2" << endl;
        return false;
    }
    ++i;
    for (i; i < r.size(); i++) {
        if (r[i] < '0' || r[i] > '9') {
            // cout << "v3 " << r[i] << endl;
            return false;
        }
    }
    // cout << "v4" << endl;
    return true;
}

void mov(int r[], string t) {
    // cout << "move" << endl;
    char c = t[0];
    int n = 0;
    for (int i = 1; i <= t.size() - 1; i++) {
        int o = t[i] - '0';
        n *= 10;
        n += o;
    }
    if (c == 'A') {
        r[0] -= n;
    } else if (c == 'S') {
        r[1] -= n;
    } else if (c == 'W') {
        r[1] += n;
    } else if (c == 'D') {
        r[0] += n;
    }
    // cout << ":" << t << " " << n << " " << to_string(r[0]) << " " << to_string(r[1]) << endl;
}

int main() {
    string r;
    getline(cin, r);
    int co[2] = {0};

    int p = 0, c = 0;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] == ';') {
            string t = r.substr(p, i - p); // POE: i not c
            // cout << ":: " << t << "_" << r[i] << endl;
            // ++c; // POE:
            p = i + 1; // POE: i not c
            if (!valid(t)) {
                continue;
            } else {
                // cout << "11" << endl;
                mov(co, t); // POE:
            }
        }
        ++c;
    }

    cout << to_string(co[0]) << "," << to_string(co[1]) << endl;
    return 0;
}
//   W
// A . D
//   S
// 64 位输出请用 printf("%lld")