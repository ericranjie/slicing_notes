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

    stack<char> ost; // operator-stack
    stack<int> nst; // number-stack

    bool m = false; // minus-flag
    for (int i = 0; i < t.size(); i++) {
        if (is_number(t[i])) { // number
            int n = t[i] - '0';
            if (m) {
                n *= (-1);
            }
            nst.push(n);
            m = false;
        }
    } else if (is_operator(t[i])// operator
        is_lbracket(t[i])) { // left-bracket
        ost.push(t[i]);
    } else if (is_rbracket(t[i])) { // right-bracket
        
        continue;
    }

    return 0;
}
// 3+2*{1+2*[-4/(8-6)+7]}
// 64 位输出请用 printf("%lld")