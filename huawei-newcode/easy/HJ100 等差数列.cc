#include <iostream>
using namespace std;

// need-recite:
int main() {
    int n;
    cin >> n;

    int res = 0;
    res += 2 * n;
    for (int i = n - 1; i > 0; i--) {
        res += (i * 3);
    }
    cout << res;

    return 0;
}