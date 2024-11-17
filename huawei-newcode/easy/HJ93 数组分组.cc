#include <iostream>
#include <vector>
using namespace std;

// need-recite-all:
bool recur(int i, vector<int> &v, int s1, int s2) {
    if (i == v.size())
        return abs(s1) == s2;
    else
        return recur(i + 1, v, s1 + v[i], s2) ||
            recur(i + 1, v, s1 - v[i], s2);
}

int main() {
    int n;
    cin >> n;
    vector<int> v; // v: vector of neither 5 nor 3
    int t;
    int s5 = 0, s3 = 0; // s5-s3: sum of 5, 3

    // Step-1: Input and classify 5, 3, none;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t % 5 == 0) s5 += t;
        else if (t % 3 == 0) s3 += t;
        else v.push_back(t);
    }

    // Step-2: Recursive;
    if (recur(0, v, 0, abs(s3 - s5)))
        cout << "true";
    else cout << "false";
    return 0;
}