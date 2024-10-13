#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    int t, na = 0, sum = 0;
    while (cin >> t) {
        if (t > 0) {
            sum += t;
            v.push_back(t);
        } else if (t < 0) {
            ++na;
        }
    }

    // cout << na << " " << sum << " " << v.size() << " ";
    cout << na << " ";
    if (v.size() > 0) {
        // double d = sum / v.size();
        // printf("%.1f", d);
        int r = sum / v.size();
        int d = (sum * 100) / v.size();
        int m2 = d % 10; // POE:
        d = d / 10;
        int m1 = d % 10;
        if (m2 >= 5) ++m1;
        printf("%d.%d", r, m1);
    } else {
        cout << "0.0";
    }
    return 0;
}
// 64 位输出请用 printf("%lld")