#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 个子 对子 三个
// 顺子（连续5张）
// 炸弹（四个）
// 对王

int trans(string t) {
    if (t.size() == 1) {
        if (t[0] >= '0' && t[0] <= '9') {
            return t[0] - '0';
        } else if (t[0] == 'J') {
            return 11;
        } else if (t[0] == 'Q') {
            return 12;
        } else if (t[0] == 'K') {
            return 13;
        } else if (t[0] == 'A') {
            return 14;
        } else if (t[0] == '2') {
            return 15;
        } else if (t[0] == 'o') {
            return 16;
        } else if (t[0] == 'O') {
            return 17;
        }
    } else if (t.size() == 2) {
        if (t[0] == '1' && t[1] == '0') {
            return 10;
        }
    }
    return 0;
}

vector<string> extract(string t) {
    vector<string> r; // result

    int s = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != ' ') {

        } else {
            if (t.substr(s, i - s) == "joker") {
                r.push_back("o");
            } else if (t.substr(s, i - s) == "JOKER") {
                r.push_back("O");
            } else {
                r.push_back(t.substr(s, i - s)); // POE:
            }
            // cout << t.substr(s, i - s) << " ";
            s = i + 1;
        }
    }
    if (t.substr(s, t.size() - s) == "joker") {
        r.push_back("o");
    } else if (t.substr(s, t.size() - s) == "JOKER") {
        r.push_back("O");
    } else {
        r.push_back(t.substr(s, t.size() - s));
    }
    return r;
}

int main() {
    string t;
    getline(cin, t);
    int s = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '-') {
            s = i;
            break;
        }
    }
        string a = t.substr(0, s);
        string b = t.substr(s + 1, t.size() - s);
        // cout << a << endl << b << endl;
        vector<string> va, vb;
        va = extract(a);
        vb = extract(b);
        int m = va.size();
        int n = vb.size();

        // cout << m << " " << n << endl;
        if (m != n) {
            // cout << va[0] << " " << vb[0] << endl;
            if (va[0] == "o") {
                cout << a << endl;
            } else if (vb[0] == "o") {
                cout << b << endl;
            } else if (m == 4) {
                cout << a << endl;
            } else if (n == 4) {
                cout << b << endl;
            } else {
                cout << "ERROR" << endl;
            }
        }

        if (m == 2 && n == 2) { // double-or-joker
                if (trans(va[0]) > trans(vb[0])) {
                    cout << a << endl;
                } else {
                    cout << b << endl;
                }
            // }
        } else if ((m == 1 && n == 1) || (m == 3 && n == 3)) {
            if (trans(va[0]) > trans(vb[0])) {
                cout << a << endl;
            } else {
                cout << b << endl;
            }
        } else if ((m == 5 && n == 5) || (m == 4 && n == 4)) {
            if (trans(va[0]) > trans(vb[0])) {
                cout << a << endl;
            } else {
                cout << b << endl;
            }
        }

        return 0;
    }

// A-10
// joker-4
// J J J J-3 3 3 3
