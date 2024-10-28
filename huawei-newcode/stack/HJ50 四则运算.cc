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

// POE: priority-of-operator: -4/(8-6)+7
int comp(int a, int b, char o) { // compute
    cout << o << " " << to_string(a) << " " << to_string(b) << endl;
    if (o == '+') {
        return a + b;
    } else if (o == '-') {
        return b - a; // POE: minus-order
    } else if (o == '*') {
        return a * b;
    } else if (o == '/') {
        return b / a; // POE: same-as-upper
    }
    return 1; // error
}

int main() {
    string t;
    getline(cin, t);

    stack<char> bst; // bracket-stack
    stack<int> nst; // number-stack
    stack<char> ost; // operator-stack

    bool m = false; // minus-flag
    for (int i = 0; i < t.size(); i++) {
        if (is_number(t[i])) { // number
            int n = t[i] - '0';
            if (m) {
                n *= (-1);
            }
            nst.push(n);
            m = false;
        } else if (is_operator(t[i])) { // operator
            if ((t[i] == '-') && i - 1 >= 0 &&
                is_lbracket(t[i - 1])) {
                m = true;
                continue; // jump
            }
            if (((t[i] == '*') || (t[i] == '/')) &&
                    i + 1 < t.size() &&
                    (t[i + 1] != '{') &&
                    (t[i + 1] != '(') &&
                    (t[i + 1] != '[')) {
                char o = t[i];
                int a = nst.top();
                nst.pop();
                int b = t[i + 1];
                int r = comp(a, b, o);
                nst.push(r);
                m = false;
                ++i;
                continue;
            }
            ost.push(t[i]);
            m = false;
        } else if (is_lbracket(t[i])) { // left-bracket
            bst.push(t[i]);
            m = false;
        } else if (is_rbracket(t[i])) { // right-bracket
            bst.pop();
            char o = ost.top();
            ost.pop();
            int a = nst.top();
            nst.pop();
            int b = nst.top();
            nst.pop();
            int r = comp(a, b, o);
            nst.push(r);
            m = false;
        }
    }

    while (ost.size() > 0) {
        char o = ost.top();
        ost.pop();
        int a = nst.top();
        nst.pop();
        int b = nst.top();
        nst.pop();
        int r = comp(a, b, o);
        nst.push(r);
    }

    cout << nst.top();

    return 0;
}
// 3+2*{1+2*[-4/(8-6)+7]}
// 64 位输出请用 printf("%lld")