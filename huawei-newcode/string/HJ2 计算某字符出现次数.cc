#include <iostream>
#include <unordered_map>
#include <initializer_list>
#include <unistd.h>
using namespace std;

// hashmap-solution
int main(int argc, char *argv[]) {
  string t;
  char c;

  getline(cin, t);
  cin >> c;
  if (c >= 'A' && c <= 'Z') {
    c += 32;
  }

  unordered_map<char, int> m;
  for (auto it = t.begin(); it != t.end(); it++) {
    char i = *it;
    if (i >= 'A' && i <= 'Z') {
      i += 32;
    }
    if (m.count(i) == 0) {
      m.insert(make_pair(i, 1));
      // m.insert({*it, 1}); // ?
    } else {
      m[i]++;
    }
  }
  cout << to_string(m[c]) << endl;

  return 0;
}