#include <iostream>
#include <vector>
// #include <queue>
#include <map>
using namespace std;

static string cut(string t) { // extract
    string r;

    // int a = t.find_last_of("\");
    int a, b;
    for (int i = t.size() - 1; i >= 0; i--) { // b = space
        if (t[i] == ' ') {
            b = i;
            break;
        }
    }
    for (int i = t.size() - 1; i >= 0; i--) { // a = backslash
        if (t[i] == '\\') {
            a = i;
            break;
        }
    }
    int s = 0; // start
    if (b - a <= 16) {
        s = a + 1;
        // r = t.substr(a + 1, b - a); // POE: donot-1
    } else {
        s = b - 16;
        // r = t.substr(b - 16, 16);
    }
    r = t.substr(s, t.size() - s); // POE: donot-1; exp: 3

    // n = 0;
    // for (int i = b + 1; i < t.size(); i++) { // POE:
    //     n *= 10;
    //     n += (t[i] - '0');
    //     // cout << n << endl;
    // }

    // cout << r << " " << n << " " << b << " " << t.size() << endl;
    return r;
}

int main() {
    string t;
    // vector<string> v;

    map<string, int> cmp; // postfix -> count
    map<int, string> tmp; // POE: time -> postfix
    // queue<pair<string, int>> que; // postfix -> line-num
    int time = 0; // time
    while (getline(cin, t)) {
        // v.push_back(t);
        string r = cut(t); // remain-postfix-and-line-num
        // cout << r << endl;
        if (!cmp.count(r)) {
            tmp.insert({time, r});
        }
        ++time;
        ++cmp[r];
    }

    auto it = tmp.begin();
    int c = 0;
    if (tmp.size() <= 8) {
    } else {
        for (int i = 0; i < tmp.size() - 8; i++) {
            it++;
        }
    }

    // for (auto it = tmp.rbegin(); it != tmp.rend(); it++) {
    for (it; it != tmp.end(); it++) {
        ++c;
        cout << it->second << " " << cmp[it->second] << endl;
        if (c >= 8) { // POE: must-be-equal
            break;
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")