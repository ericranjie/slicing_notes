#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> extract(string t) { // pre-condition: must-be-valid
    vector<int> v;

    int o = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != '.') {
            o *= 10;
            o += t[i] - '0';
        } else {
            v.push_back(o);
            o = 0; // reset
        }
    }
    v.push_back(o); // POE: remember-this
    return v;
}

bool veri_mask(vector<int> v) { // POE: verify-mask
    bool one = true;
    int nc = 0; // 0-1-change-number
    int p = 0; // pre = 0
    if (v[0] < 255) { // POE:
        return false;
    }
    int bit = 0;
    for (int i = v.size(); i >= 0; i--) {
        int a = v[i];
        bit = 0;
        while (a > 0) {
            ++bit;
            int m = a % 2;
            if (m == 0) {
                one = false;
                if (p == 1) {
                    ++nc;
                    p = 0;
                }
            } else if (m == 1) {
                // if (!one) { // POE: must-not-have-this
                //     return false;
                // }
                if (p == 0) {
                    ++nc;
                    p = 1;
                }
            }
            a /= 2;
        }
        if (bit < 8) { // higher-bit-is-zero
            if (p == 1) {
                ++nc;
                p = 0;
            }
        }
    }
    if (nc > 2) {
        return false;
    }
    return true;
}

bool veri(vector<int> v) { // verify
    if (v.size() != 4) {
        return false;
    }

    for (int i = 0; i < 4; i++) {
        if (!(v[i] >= 0 && v[i] <= 255)) {
            return false;
        }
    }

    return true;
}

int mask(int m, int a) {
    int r = 0, i = 0, l = 0;
    while (m > 0) {
        int mi = m % 2;
        int ai = a % 2; 
        
        i = (mi & ai);
        r += i * pow(2, l);

        ++l;
        m = m >> 1;
        a = a >> 1;
    }

    return r;
}

int main() {
    string m, a, b; // musk - ip1 - ip2;
    getline(cin, m);
    getline(cin, a);
    getline(cin, b);

    vector<int> vm, va, vb;
    vm = extract(m);
    va = extract(a);
    vb = extract(b);

    // Step-1: Verify valid IP and mask;
    if (!veri(vm) || !veri(va) || !veri(vb)) {
        cout << 1 << endl;
        return 0;
    }

    if (!veri_mask(vm)) {
        cout << 1 << endl;
        return 0;
    }

    // Step-2: Verify same(0) or not(2);
    for (int i = 0; i < vm.size(); i++) {
        if (mask(vm[i], va[i]) != mask(vm[i], vb[i])) {
            cout << 2 << endl;
            return 0;
        }
     }

    cout << 0 << endl;
    return 0;
}

// 254.255.0.0
// 85.122.52.249
// 10.57.28.117

// 1.255.255.0
// 187.39.235.7
// 219.79.189.231

// 255.255.0.1
// 97.151.30.191
// 240.102.155.58

// 255.255.252.0
// 173.225.245.45
// 69.138.93.228

// 255.255.255.0
// 192.168.224.256
// 192.168.10.4
// 255.0.0.0
// 193.194.202.15
// 232.43.7.59
// 255.255.255.0
// 192.168.0.254
// 192.168.0.1