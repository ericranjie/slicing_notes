#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> v;
    int t, na = 0, sum = 0;

    while (cin >> t) {
        if (t >= 0) {
            v.push_back(t);
            sum += t;
        }
        else
            na++;
        // cout << t << endl;
    }
    float f = 0.0;

    if (v.size() > 0)
        f = sum / v.size();

    cout << na << endl;

    if (v.size() > 0) {
        int d = (sum * 100) / v.size();
        int m2 = d % 10;
        d = d / 10;
        int m1 = d % 10;
        d = d / 10;
        if (m2 >= 5) ++m1;
        printf("%d.%d", d, m1);
    } else {
        cout << "0.0";
    }
    return 0;
}
// 64 位输出请用 printf("%lld")