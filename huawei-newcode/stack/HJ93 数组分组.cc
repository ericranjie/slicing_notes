#include <iostream>
#include <vector>
using namespace std;

// recite-all:
bool recur(int i, vector<int> &v, int s1, int s2) {
    if (i == v.size()) {
        return abs(s1) == s2;
    } else {
        return recur(i + 1, v, s1 + v[i], s2) ||
            recur(i + 1, v, s1 - v[i], s2);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int t;
    int s5 = 0, s3 = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        // v.push_back(t);
        if (t % 5 == 0) {
            s5 += t;
        } else if (t % 3 == 0) {
            s3 += t;
        } else {
            v.push_back(t);
        }
    }

    if (recur(0, v, 0, abs(s3 - s5))) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
// 64 位输出请用 printf("%lld")