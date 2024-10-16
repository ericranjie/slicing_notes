#include <iostream>
#include <vector>
// #include <stack>
using namespace std;

int comp(int a, int b, char o) { // compute
    int r = 0;

    return r;
}

int main() {
    string t;
    getline(cin, t);

    vector<int> nst; // num-stack
    vector<char> ost; // operator-stack
    vector<char> bst; // bracket-stack

    int n = 0, r = 0;
    for (int i = 0; i < t.size(); i++) {
        if ((t[i] == '+') || (t[i] == '-') ||
            (t[i] == '*') || (t[i] == '/')) { // + - * /
            nst.push_back(n);
            ost.push_back(t[i]);
            if (bst.size() == 0 && nst.size() >= 2 && ost.size() >= 1) {
                char c = *ost.rbegin();
                ost.pop_back();
                int a = *nst.rbegin();
                nst.pop_back();
                int b = *nst.rbegin();
                nst.pop_back();

                r += compute(a, b, c);
            }
        } else if ((t[i] >= '0') && (t[i] <= '9')) { // num
            n = n * 10;
            n += (t[i] - '0');
        } else if ((t[i] >= '(') && (t[i] <= ')')) { // ()
            nst.push_back(n);
            ost.push_back(t[i]);
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")