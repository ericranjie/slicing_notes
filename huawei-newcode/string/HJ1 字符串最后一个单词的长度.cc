#include <iostream>
#include <iterator>
#include <unistd.h>
using namespace std;

// std-iostream-solution:
int main(int argc, char *argv[]) {
  string t;
  int c = 0;
  getline(cin, t);
 
  if (t.length() == 0) {
    cout << "0" << endl;
    return 0;
  }

  for (auto it = t.rbegin(); it != t.rend(); it++) {
    if (*it == ' ') {
      break;
    }
    c++;
  }

  cout << to_string(c) << endl;

  return 0;
}
