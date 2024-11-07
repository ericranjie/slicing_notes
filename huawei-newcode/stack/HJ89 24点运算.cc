#include <iostream>
#include <vector>
using namespace std;

// abandon: or-find-solution

// If mixed +- and */, and first is +or-,
// then only allow (+or-) appear once.
// Same, if first is *or/, then last two must be +or-
int recur(vector<double> &t, double eps,
    vector<string> &res, vector<char> &ops, vector<vector<char>> &opres) {
    // cout << t.size() << " " << t[0] << endl;
    if (res.size() == 1) { // success:already-has-result
        return 0;
    } else if (t.size() == 1 && t[0] == 24) {
        // cout << "s" << endl;
        for (auto o : ops) {
            cout << o << " ";
        }
        cout << endl;
        opres.push_back(ops);
        return 0;
    } else if (t.size() == 1 && t[0] != 24) { // failed
        return 0;
    }

    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < i; j++) { // POE:segment-fault
            double a = t[i];
            double b = t[j];

            vector<double> o{a + b, a - b, b - a, a * b};
            vector<char> vc{'+', '-', '-', '*', '/'};
            if (a > eps) {
                o.push_back(b / a);
            }
            if (b > eps) {
                o.push_back(a / b);
            }

            t.erase(t.begin() + i);
            t.erase(t.begin() + j);

            for (int k = 0; k < o.size(); k++) {
                t.push_back(o[k]);
                ops.push_back(vc[k]);
                recur(t, eps, res, ops, opres);
                ops.pop_back();
                t.pop_back();
            }

            t.insert(t.begin() + j, b);
            t.insert(t.begin() + i, a);
        }
    }

    // cout << "return" << endl;
    return 0;
}

int main() {
    string t;
    getline(cin, t);

    vector<string> v;
    int s = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == ' ') {
            v.push_back(t.substr(s, i - s));
            // cout << t.substr(s, i - s) << endl;
            s = i + 1;
        }
    }
    v.push_back(t.substr(s, t.size() - s));
    // cout << t.substr(s, t.size() - s) << endl;

    vector<int> a; // char-to-int-vector
    for (int i = 0; i < v.size(); i++) {
        if (v[i].size() == 1) {
            char c = v[i][0]; // char
            int ci = 0; // char-to-int
            if (c == 'A') {
                ci = 1;
            } else if (c == 'J') {
                ci = 11;
            } else if (c == 'Q') {
                ci = 12;
            } else if (c == 'K') {
                ci = 13;
            } else if (c >= '2' && c <= '9') {
                ci = c - '0';
            }
            a.push_back(ci);
            cout << ci << endl;
        } else if (v[i].size() == 5 &&
            (v[i] == "joker" || v[i] == "JOKER")) {
            cout << "ERROR" << endl;
            return 0;
        }
    }

    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }

    // step-last:
    vector<string> res;
    double eps = 0.001;
    vector<double> d(a.begin(), a.end());
    vector<char> ops;
    vector<vector<char>> opres;
    recur(d, eps, res, ops, opres);

    cout << opres.size() << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")