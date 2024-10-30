#include <iostream>
#include <vector>
using namespace std;

// + *
// - /

void recur(vector<double> &v, double eps, bool &res) {
    if (res) { // success-true
        return;
    }
    if (v.size() == 1) {
        if (v[0] == 24) {
            res = true;
        } else {
            res = false;
        }
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            double a = v[i];
            double b = v[j];
            int c;
            vector<double> t{a + b, a - b, b - a, a * b};
            if (a > eps) t.push_back(b / a);
            if (b > eps) t.push_back(a / b);

            v.erase(v.begin() + i);
            v.erase(v.begin() + j);

            for (double d : t) {
                v.push_back(d);
                recur(v, eps, res);
                v.pop_back();
            }

            v.insert(v.begin() + j, b);
            v.insert(v.begin() + i, a);
        }
    }

    return;
}

// recite-all:
int main() {
    vector<int> v;
    double eps = 0.001; // epision
    int t;
    for (int i = 0; i < 4; i++) {
        cin >> t;
        v.push_back(t);
        // cout << t << " ";
    }

    bool res = false;
    vector<double> a(v.begin(), v.end());
    recur(a, eps, res);

    if (res) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")