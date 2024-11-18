#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;

// std-cheat-solution:
// need-reveal:
int main(int argc, char *argv[]) {
    int num = 0;
    vector<string> r; // r: raw

    cin >> num;
    cin.ignore(256, '\n'); // POE:

    for (int i = 0; i < num; i++) {
      string t;
      getline(cin, t);
      r.push_back(t);
    }

    sort(r.begin(), r.end());

    for (int i = 0; i < num; i++) {
      cout << r[i] << endl;
    }

    return 0;
}