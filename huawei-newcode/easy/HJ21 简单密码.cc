#include <iostream>
#include <map>
using namespace std;

int main() {
    string r;
    getline(cin, r);

    map<char, char> mp;
    mp['a'] = mp['b'] = mp['c'] = '2';
    mp['d'] = mp['e'] = mp['f'] = '3';
    mp['g'] = mp['h'] = mp['i'] = '4';
    mp['j'] = mp['k'] = mp['l'] = '5';
    mp['m'] = mp['n'] = mp['o'] = '6';
    mp['p'] = mp['q'] = mp['r'] = mp['s'] = '7';
    mp['t'] = mp['u'] = mp['v'] = '8';
    mp['w'] = mp['x'] = mp['y'] = mp['z'] = '9';

    for (int i = 0; i < r.size(); i++) {
        if (r[i] >= 'a' && r[i] <= 'z') {
            r[i] = mp[r[i]];
        }
        if (r[i] >= 'A' && r[i] <= 'Z') {
            if (r[i] >= 'A' && r[i] <= 'Y') {
                r[i] += 32;
                ++r[i];
            } else if (r[i] == 'Z') {
                r[i] = 'a';
            }
        }
        cout << (char)r[i];
    }

    return 0;
}