#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;

// std-cheat-solution:
int main(int argc, char *argv[]) {
  int num = 0;
  vector<string> raw;

  cin >> num;
  cin.ignore(256, '\n'); // POE:

  for (int i = 0; i < num; i++) {
    string tmp;
    getline(cin, tmp);
    raw.push_back(tmp);
  }

  sort(raw.begin(), raw.end());

  for (int i = 0; i < num; i++) {
    cout << raw[i] << endl;
  }

  return 0;
}