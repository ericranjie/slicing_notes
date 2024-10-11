#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(int argc, char *argv[]) {
  string key, text, res;
  getline(cin, key);
  getline(cin, text);
  // cout << key << " " << text;

  unordered_set<char> st;
  unordered_map<char, char> mp;
  string tmp;
  for (auto it = key.begin(); it != key.end(); it++) {
    if (!st.count(*it)) {
      st.insert(*it);
      tmp.push_back(*it);
    }
  }
  for (char c = 'a'; c <= 'z'; c++) {
    if (!st.count(c))
      tmp.push_back(c);
  }

  // cout << "tmp = " << tmp << endl;
  auto it = tmp.begin();
  for (char c = 'a'; c <= 'z'; c++) {
    mp.insert(make_pair(c, *it));
    it++;
  }

  for (auto it = text.begin(); it != text.end(); it++) {
    *it = mp[*it];
  }

  cout << text << endl;

  return 0;
}