#include <iostream>
#include <algorithm>
#include <unistd.h>
using namespace std;

// Brute-force-solution:
// need-reveal:
int main(int argc, char *argv[]) {
    string t;
    getline(cin, t);
    reverse(t.begin(), t.end());

    cout << t << endl;

    return 0;
}