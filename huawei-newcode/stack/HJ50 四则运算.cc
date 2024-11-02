#include <iostream>
#include <stack>
using namespace std;

/*
3+2*{1+2*[-4/(8-6)+7]}
3+2*{1+2*[-4/2+7]}
3+2*{1+2*[-2+7]}
3+2*{1+2*5}
3+2*{1+10}
3+2*11
3+22
25
*/

bool is_number(char c) {
    return (c >= '0') && (c <= '9');
}
bool is_operator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}
bool is_lbracket(char c) {
    return (c == '{') || (c == '(') || (c == '[');
}
bool is_rbracket(char c) {
    return (c == '}') || (c == ')') || (c == ']');
}

// recite:
int compute(string t) {
    // cout << t << endl;
    // stack<int> nst; // number-stack
    int i = 0;
    int c = 0; // current-number-value
    int cur_res = 0;
    char op = '+'; // POE:
    int res = 0;
    while (i < t.size()) {
        if (is_number(t[i])) { // is-number
            c *= 10;
            c += t[i] - '0';
        } else if (is_lbracket(t[i])) { // left-bracket
            int cnt = 0; // valid-pathesis-count
            int j = 0;
            for (j = i; j < t.size(); j++) {
                if (is_lbracket(t[j])) {
                    ++cnt;
                } else if (is_rbracket(t[j])) {
                    --cnt;
                }
                if (cnt == 0) {
                    break;
                }
            }
            c = compute(t.substr(i + 1, j - i - 1)); // POE:
            i = j; // POE: not+1
        }
        // cout << "c: " << c << " t[i]: " << t[i] << " curres: "
        //     << cur_res << endl;
        if (is_operator(t[i]) || i == t.size() - 1) {
            char to = t[i]; // tmp-operator
            if (op == '+') {
                cur_res += c;
            } else if (op == '-') {
                cur_res -= c;
            } else if (op == '*') {
                cur_res *= c;
            } else if (op == '/') {
                cur_res /= c;
            }
            // cout << "curres: " << cur_res << " c: " << c
            //     << " t[i]: " << t[i] << endl;
            if (t[i] == '+' || t[i] == '-' || i == t.size() - 1) { // POE:
                res += cur_res;
                cur_res = 0;
            }
            op = to; // renew-operator
            c = 0;
        }
        ++i;
    }

    // cout << ": " << res << endl;
    return res;
}

// recite:
int main() {
    string t;
    getline(cin, t);

    int r = compute(t);
    cout << r << endl;

    return 0;
}
// 3+2*{1+2*[-4/(8-6)+7]}
// 64 位输出请用 printf("%lld")