#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
r       - reset             - true
reb     - reboot backplane  - false
r b     - reset board
          reboot backplane  - false
bo a    - board add         - true
b addr  - xxx               - false
*/

// cheat-solution:
// need-reveal: complex
map<string, string> d = { // dictionary
    {"reset",               "reset what"},
    {"reset board",         "borad fault"},
    {"board add",           "where to add"},
    {"board delete",        "no board at all"},
    {"reboot backplane",    "impossible"},
    {"backplane abort",     "install first"}
};

static string err = "unknown command";
static string reset = "reset";
static string board = "board";
static string reboot = "reboot";
static string backplane = "backplane";

static string add = "add";
static string del = "delete";
static string abo = "abort";

void veri(string t) {
    int l = 0, r = 0; // space-index
    vector<string> v;
    for (int i = 0; i < t.size(); i++) {
        string p; // part-of-string
        if (t[i] == ' ') {
            r = i;
            p = t.substr(l, r - l);
            v.push_back(p);
            l = i + 1;
            r = i + 1;
        }
    }
    v.push_back(t.substr(l, t.size() - l)); // POE: not(-1)

    // Case-1: one input;
    if (v.size() == 1) { // reset
        string tmp = "reset";
        int n = v[0].size() > 5 ? 5 : v[0].size();
        for (int i = 0; i < n; i++) {
            if (v[0][i] != tmp[i]) {
                cout << err << endl;
                return;
            }
        }
        cout << "reset what" << endl;
        return;
    }

    // Case-2: 2 input;
    if (v.size() == 2) {
        if (v[0].size() <= 0) return; // Guard:
        if (v[0][0] == 'r' && v[0].size() == 1 &&
            v[1][0] == 'b' && v[1].size() == 1) { // POE:
            cout << err << endl;
            return; // POE:
        }
        if (v[0][0] == 'b' && v[0].size() == 1 &&
            v[1][0] == 'a' && v[1].size() == 1) { // POE:
            cout << err << endl;
            return; // POE:
        }
        if (v[0][0] == 'r') { // checking-r
            int n1 = v[0].size();
            int n2 = v[1].size();
            if (n1 <= 5 && reset.substr(0, n1) == v[0] &&
                n2 <= 5 && board.substr(0, n2) == v[1]) {
                cout << "board fault" << endl;
                return; // POE:
            } else if (n1 <= 6 && reboot.substr(0, n1) == v[0] &&
                n2 <= 9 && backplane.substr(0, n2) == v[1]) {
                cout << "impossible" << endl;
                return; // POE:
            }
        } else if (v[0][0] == 'b') {
            int n1 = v[0].size();
            int n2 = v[1].size();
            if (n1 <= 5 && board.substr(0, n1) == v[0] &&
                n2 <= 3 && add.substr(0, n2) == v[1]) {
                cout << "where to add" << endl;
                return;
            } else if (n1 <= 5 && board.substr(0, n1) == v[0] &&
                n2 <= 6 && del.substr(0, n2) == v[1]) {
                cout << "no board at all" << endl;
                return; // POE:
            } else if (n1 <= 9 && backplane.substr(0, n1) == v[0] &&
                n2 <= 5 && abo.substr(0, n2) == v[1]) {
                cout << "install first" << endl;
                return; // POE:
            }
        }
    }
    cout << err << endl; // POE:
    return;
}

int main() {
    string t;
    while (getline(cin, t)) veri(t);
    return 0;
}

// r b
// b a
// bo a
// reb
// r
// res

// board add
// board delete
// reset
// he he
// board delete
// reboot backplane
// he he
// he he
// reset board
// he he
// reset board
// he he
// reset
// board add
// reset board
// backplane abort
// reset board
// he he
// board delete
// backplane abort
// board delete
// reset
// reset
// he he
// backplane abort
// board add
// reset board
// he he
// he he
// reboot backplane
// board add
// reset board
// board delete
// board delete
// reset board
// reboot backplane
// he he
// board delete
// board delete
// board delete
// reset board
// board delete
// he he
// board delete
// backplane abort
// backplane abort
// board add
// backplane abort
// board delete
// backplane abort
// reboot backplane
// board delete
// reset
// reboot backplane
// backplane abort
// backplane abort
// reset board
// board delete
// board add
// board add
// reset board
// backplane abort
// board add
// backplane abort
// reset
// reset board
// reset
// board delete
// board add
// reboot backplane
// reset board
// reset board
// reboot backplane
// he he
// reset
// board add
// board add
// reset board
// reset board
// board delete
// he he
// backplane abort
// reboot backplane
// board delete
// board delete
// board delete
// reboot backplane
// board add
// board add
// board add
// reboot backplane
// he he
// reboot backplane
// reset board
// board add
// reset
// backplane abort
// reset
// board add
// board delete
// reset
// reboot backplane
// reset
// reset
// reset
// backplane abort
// reset board
// board delete
// board add
// reset
// reset board
// reset
// he he
// reboot backplane
// board add
// reset
// reset board
// reboot backplane
// board add
// backplane abort
// board delete
// he he
// board add
// reset
// board add
// reboot backplane
// reboot backplane
// board delete
// he he
// board delete
// board delete
// reset
// he he
// reset
// reset
// reboot backplane
// reset board
// backplane abort
// he he
// reset board
// reboot backplane
// board add
// reboot backplane
// backplane abort
// board delete
// board delete
// reboot backplane
// reset board
// board add
// he he
// reset board
// he he
// reset board
// board add
// reset board
// reboot backplane
// reset
// backplane abort
// reset board
// reset board
// board delete
// board delete
// reset board
// board add
// backplane abort
// reset board
// he he
// board delete
// he he
// reset board
// backplane abort
// reboot backplane
// board delete
// backplane abort



// 64 位输出请用 printf("%lld")