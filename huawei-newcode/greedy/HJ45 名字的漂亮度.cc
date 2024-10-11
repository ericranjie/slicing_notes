#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO:
void quicksort(char t[]) {

}

int helper(string t) {
    char mp[26] = {0};
    for (auto it = t.begin(); it != t.end(); it++) {
        mp[*it]++;
    }
    
}

int main() {
    vector<string> raw;
    int num;

    cin >> num;
    cin.ignore(256, '\n');

    for (int i = 0; i < num; i++) {
        string tmp;
        getline(cin, tmp);
        raw.push_back(tmp);
        // cout << tmp << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")