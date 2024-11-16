#include <iostream>
#include <algorithm>
using namespace std;

// std-cheat-solution:
// need-reveal:
int main() {
    string raw;
    getline(cin, raw);

    reverse(raw.begin(), raw.end());

    cout << raw << endl;
    return 0;
}