#include <iostream>
#include <unistd.h>
#include <string.h> // POE:
using namespace std;

int main(int argc, char *argv[]) {
  char mp[127];
  memset(mp, 0, 127);

  string t;
  getline(cin, t);
  for (auto it = t.begin(); it != t.end(); it++) {
    if (mp[*it] == 0) {
      mp[*it] = 1;
    }
  }

  int res = 0;
  for (int i = 0; i < 127; i++) {
    res += mp[i];
  }

  cout << to_string(res) << endl;

  return 0;
}
