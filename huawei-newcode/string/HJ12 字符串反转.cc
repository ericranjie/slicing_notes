#include <iostream>
#include <algorithm>
#include <unistd.h>
using namespace std;

// brute-force-solution:
int main(int argc, char *argv[]) {
  string t;
  getline(cin, t);
  reverse(t.begin(), t.end());

  cout << t << endl;

  return 0;
}