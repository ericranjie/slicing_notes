#include <iostream>
#include <algorithm>
// #include <unordered_map>
#include <map>
using namespace std;

int main() {
    int n, index[500], value[500];
    // unordered_map<int, int> mp; // POE:
    map<int, int> mp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> index[i];
        cin >> value[i];
        if (!mp.count(index[i]))
            mp.insert({index[i], value[i]});
        else
            mp[index[i]] += value[i];
    }
#if 0
    vector<pair<int, int> > v(mp.begin(), mp.end());
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++) {
#endif
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")