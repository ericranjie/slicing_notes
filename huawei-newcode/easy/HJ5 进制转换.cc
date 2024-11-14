#include <iostream>
#include <vector>
using namespace std;

void trans(string t) {
    if (t.size() <= 2) { // Guard: Invalid;
        cout << "0" << endl;
        return;
    }

    int r = 0; // Result;
    for (int i = 2; i < t.size(); i++) { // Start from index-2("0x");
        char c = t[i];
        int m = 0;
        if (c >= '0' && c <= '9') { // Is number;
            m = (c - '0');
        } else if (c >= 'A' && c <= 'F') { // Is alpha; POE: not E
            m = (c - 'A' + 10);
        }

        int j = 1, k = t.size() - i - 1; // POE:
        while (k-- > 0) {
            j *= 16;
        }
        m = m * j;
        r += m;
    }
    cout << r << endl;
    return;
}

int main() {
    string t;
    vector<string> v;
    while (getline(cin, t)) { // Multiple testcase;
        v.push_back(t);
        trans(t);
    }

    return 0;
}