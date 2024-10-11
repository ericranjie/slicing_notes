#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a > b)
        return gcd(b, a - b);
    else if (a < b)
        return gcd(a, b - a);
    else return a;
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    int g = gcd(a, b);
    if (g == 1) cout << a * b << endl;
    else {
        int aq = a / g;
        int bq = b / g;
        cout << aq * bq * g << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")