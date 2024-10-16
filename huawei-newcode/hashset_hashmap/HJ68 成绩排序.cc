#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

// stl-map-cheat-solution:
int main() {
    int n, d;
    map<int, vector<string>> mp;
    cin >> n;
    cin >> d;
    cin.ignore(256, '\n'); // POE:
    // vector<pair<string, int>> v;

    // cout << "-" << n << " " << d << endl;

    string t;
    while (getline(cin, t)) {
        string name; int score = 0; bool space = false;
        // cout << "--" << t << endl;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == ' ') {
                space = true;
                continue;
            } else if (t[i] >= '0' && t[i] <= '9') { // number
                if (space) {
                    score *= 10;
                    score += (t[i] - '0');
                }
            } else {
                if (!space) {
                    name.push_back(t[i]);
                }
            }
        }
        mp[score].push_back(name);
        // cout << name << to_string(score) << endl;
    }

    if (d == 1) {
        for (auto it = mp.begin(); it != mp.end(); it++) {
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i] << " ";
                cout << it->first << endl;
            }
            // cout << endl;
        }
    } else if (d == 0) {
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            for (int i = 0; i < it->second.size(); i++) {
                cout << it->second[i] << " ";
                cout << it->first << endl;
            }
            // cout << endl;
        }
    }

    return 0;
}
// } else if ((t[i] >= 'a' && t[i] <= 'z') ||
//     (t[i] >= 'A' && t[i] <= 'Z'))
// 64 位输出请用 printf("%lld")