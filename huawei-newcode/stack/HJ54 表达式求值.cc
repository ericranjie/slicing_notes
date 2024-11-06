#include <iostream>
#include <vector>
// #include <stack>
using namespace std;

bool is_number(char c) {
    return (c >= '0') && (c <= '9');
}
bool is_operator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}
bool is_lbracket(char c) {
    return (c == '(');
}
bool is_rbracket(char c) {
    return (c == ')');
}

int compute(string t) { // compute
    char o = '+'; // last-operator
    int n = 0;
    int cur_res = 0;
    int res = 0;
    for (int i = 0; i < t.size(); i++) {
        char c = t[i];
        if (is_number(c)) {
            n *= 10;
            n += c - '0';
        } else if (is_lbracket(c)) {
            int l = i + 1; // left-pointer
            int r; // right-pointer
            int j = i;
            int cnt = 0;
            for (; j < t.size(); ++j) {
                if (is_lbracket(t[j])) {
                    ++cnt;
                } else if (is_rbracket(t[j])) {
                    --cnt;
                }
                if (cnt == 0) {
                    r = j - 1;
                    break;
                }
            }
            n = compute(t.substr(l, r - l + 1)); // POE:must+1
            i = r;
        }
        if (is_operator(c) || i == t.size() - 1) {
            char to = c; // tmp-operator
            switch (o) {
                case '+':
                    cur_res += n;
                    break;
                case '-':
                    cur_res -= n;
                    break;
                case '*':
                    cur_res *= n;
                    break;
                case '/':
                    cur_res /= n;
                    break;
            }
            if (to == '+' || to == '-' || i == t.size() - 1) {
                res += cur_res;
                cur_res = 0; // reset
            }
            o = to; // renew
            n = 0;
        }
    }
    return res;
}

int main() {
    string t;
    getline(cin, t);
    cout << compute(t);

    return 0;
}
// 64 位输出请用 printf("%lld")