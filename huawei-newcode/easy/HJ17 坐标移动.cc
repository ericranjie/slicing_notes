#include <iostream>
using namespace std;

bool valid(string r) {
    if (r.size() <= 1) return false; // invalid length
    int i = 0;
    if (r[i] < 'A' || r[i] > 'Z') return false; // not upper-alpha
    ++i;
    for (i; i < r.size(); i++)
        if (r[i] < '0' || r[i] > '9') // not-number
            return false;
    return true;
}

void mov(int r[], string t) {
    char c = t[0];
    int n = 0; // n: number calculated
    for (int i = 1; i <= t.size() - 1; i++) {
        int o = t[i] - '0';
        n *= 10;
        n += o;
    }
    if (c == 'A') r[0] -= n;
    else if (c == 'S') r[1] -= n;
    else if (c == 'W') r[1] += n;
    else if (c == 'D') r[0] += n;
}

int main() {
    string r; // r: raw
    getline(cin, r);
    int co[2] = {0}; // co: coordinate

    int p = 0, c = 0;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] == ';') {
            string t = r.substr(p, i - p); // POE: i not c
            p = i + 1; // POE: i not c
            if (!valid(t)) continue;
            else
                mov(co, t); // POE:
        }
        ++c;
    }

    cout << to_string(co[0]) << "," << to_string(co[1]) << endl;
    return 0;
}
//   W
// A . D
//   S