#include <iostream>
using namespace std;

int main() {
    string t, r, o; // target - reverse - output
    getline(cin, t);

    // Step-1: Reverse all line;
    for (int i = t.size() - 1; i >= 0; i--)
        r.push_back(t[i]);

    // Step-2: Reverse each word;
    int p = 0; // previous
    int i = 0;
    for (i = 0; i < r.size() - 1; i++) {
        if (r[i] == ' ') {
            for (int j = i - 1; j >= p; j--) {
                o.push_back(r[j]);
            }
            o.push_back(r[i]);
            p = i + 1;
        }
    }

    if (p < r.size()) {
        for (int j = r.size() - 1; j >= p; j--) { // POE: not i - 1
            o.push_back(r[j]);
        }
    }

    cout << o;
    return 0;
}