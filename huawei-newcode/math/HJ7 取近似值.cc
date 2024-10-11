#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
    double f;
    cin >> f;

    f *= 10;
    int f_ = (int)f;
    int mod = f_ % 10;
    int quo = f_ / 10;
    if (mod >= 5)
        cout << quo + 1 << endl;
    else
        cout << quo << endl;
    return 0;
}