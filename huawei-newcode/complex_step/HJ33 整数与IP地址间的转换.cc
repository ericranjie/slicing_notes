#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
193 + 3 * 2^8 + 0 * 2^16 + 10 * 2 ^ 24
193         1
768         256
0           65536
167772160   16777216
167969729
*/

int main() {
    vector<string> v;
    string t;
    long long d, r = 0; // POE: int-d-too-short
    getline(cin, t);
    cin >> d; // second-input: dex-IP


    // Step-1: Input;
    string o; // current-one
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != '.') {
            o.push_back(t[i]);
        } else {
            v.push_back(o);
            o.resize(0);
            continue;
        }
    }


    // Step-2: Transfer to dex;
    string t1;
    int dex[4];
    v.push_back(o);
    for (int i = 0; i < v.size(); i++) {
        o = v[i]; // one-string
        r = 0; // one-dex
        for (int j = 0; j < o.size(); j++) {
            char c = o[j];
            r *= 10; // POE: dont-reverse-with-down-code
            r += (c - '0');
        }
        dex[i] = r;
    }
    r = 0; // reuse-result
    r = dex[0] * pow(2, 24) + dex[1] * pow(2, 16) + dex[2] * pow(2, 8)
        + dex[3] * pow(2, 0);
    cout << r << endl;


    // Step-3: Solve second input(IP: dex to string);
    int a = 0;
    a = d / pow(2, 24);
    cout << to_string(a) << ".";

    d = d - a * pow(2, 24);
    a = d / pow(2, 16);
    cout << to_string(a) << ".";

    d = d - a * pow(2, 16);
    a = d / pow(2, 8);
    cout << to_string(a) << ".";

    d = d - a * pow(2, 8);
    a = d / pow(2, 1);
    cout << to_string(d);
    return 0;
}

// 39.66.68.72
// 3868643487