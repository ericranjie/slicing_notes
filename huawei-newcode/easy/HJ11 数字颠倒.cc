#include <iostream>
using namespace std;

int main() {
    int n, m = 0; // m: module
    cin >> n;

    if (n == 0) cout << "0"; // Guard: POE:

    while (n > 0) {
        m = n % 10;
        cout << to_string(m);
        n = n / 10;
    }

    return 0;
}