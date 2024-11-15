#include <iostream>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(int argc, char *argv[]) {
    string key, text, res;
    getline(cin, key);
    getline(cin, text);

    unordered_set<char> st; // st: set of character;
    unordered_map<char, char> mp;
    string tmp; // tmp: transfered key;

    // Step-1: Remove duplicate character;
    for (auto it = key.begin(); it != key.end(); it++) {
        if (!st.count(*it)) {
            st.insert(*it);
            tmp.push_back(*it);
        }
    }

    // Step-2: Add excluded character;
    for (char c = 'a'; c <= 'z'; c++) {
        if (!st.count(c))
            tmp.push_back(c);
    }

    // Step-3: Construct dictionary (old -> new character);
    auto it = tmp.begin();
    for (char c = 'a'; c <= 'z'; c++) {
        mp.insert(make_pair(c, *it));
        it++;
    }

    // Step-4: Replace raw text;
    for (auto it = text.begin(); it != text.end(); it++) {
        *it = mp[*it];
    }

    cout << text << endl;

    return 0;
}