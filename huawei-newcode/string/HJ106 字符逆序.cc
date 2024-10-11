#include <iostream>
#include <algorithm>
using namespace std;

// std-cheat-solution:
// TODO:
int main() {
    string raw;
    getline(cin, raw);

    reverse(raw.begin(), raw.end());

    cout << raw << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")