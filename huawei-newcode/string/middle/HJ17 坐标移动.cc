#include <iostream>
using namespace std;

bool valid(string r) {
    if (r.size() <= 1) return false; // Guard-1:

    int i = 0;
    if (r[i] < 'A' || r[i] > 'Z') return false; // Guard-2:

    ++i;
    for (i; i < r.size(); i++)
        if (r[i] < '0' || r[i] > '9')
            return false;

    return true;
}

void mov(int r[], string t) {
    char c = t[0];
    int n = 0;
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
    string r;
    getline(cin, r);
    int co[2] = {0};

    int p = 0, c = 0;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] == ';') {
            string t = r.substr(p, i - p); // POE: i not c
            // ++c; // POE:
            p = i + 1; // POE: i not c
            if (!valid(t)) {
                continue;
            } else {
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