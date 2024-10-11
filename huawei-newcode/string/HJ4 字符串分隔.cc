#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
  string t;
  getline(cin, t);
  int len = t.length(), c = 0;

  for (auto it = t.begin(); it != t.end(); it++) {
    c++;
    cout << *it;
    if (c >= 8) { // POE:
      cout << endl;
      c = 0;
    }
  }

  if (len % 8 != 0) {
    int mod = len % 8;
    mod = 8 - mod;
    // cout << "mod = " << mod << endl;
    for (int i = 0; i < mod; i++) {
      cout << "0";
    }
    cout << endl;
  }

  return 0;
}