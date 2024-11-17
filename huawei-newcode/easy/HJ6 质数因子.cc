#include <iostream>
#include <cmath>
using namespace std;

// need-resite:
int main() {
    int n;
    cin >> n;

    int k = sqrt(n);
    for (int i = 2; i < k + 1; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }

    if (n != 1) // POE:
        cout << n;
    return 0;
}

// 64577