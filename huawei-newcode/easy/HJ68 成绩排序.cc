#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

// stl-map-cheat-solution:
int main() {
    int n, d;
    map<int, vector<string>> mp; // mp: map of score -> name
    cin >> n;
    cin >> d; // d: 0 ascend, 1 descend
    cin.ignore(256, '\n'); // POE:

    // Step-1: Input;
    string t;
    while (getline(cin, t)) {
        string name; int score = 0; bool space = false;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == ' ') {
                space = true;
                continue;
            } else if (t[i] >= '0' && t[i] <= '9') { // number
                if (space) {
                    score *= 10;
                    score += (t[i] - '0');
                }
            } else
                if (!space)
                    name.push_back(t[i]);
        }
        mp[score].push_back(name);
    }

    if (d == 1) {
        for (auto it = mp.begin(); it != mp.end(); it++) {
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i] << " ";
                cout << it->first << endl;
            }
        }
    } else if (d == 0) {
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i] << " ";
                cout << it->first << endl;
            }
        }
    }

    return 0;
}