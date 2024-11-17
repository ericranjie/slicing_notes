#include <iostream>
#include <unistd.h>
using namespace std;

// need-familiar: math;
int main(int argc, char *argv[]) {
    double f;
    cin >> f;

    f *= 10;
    int f_ = (int)f;
    int mod = f_ % 10; // mod: module
    int quo = f_ / 10; // quo: quotient
    if (mod >= 5)
        cout << quo + 1 << endl;
    else
        cout << quo << endl;
    return 0;
}