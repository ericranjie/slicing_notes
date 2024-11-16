#include <iostream>
using namespace std;

int main() {
    string r;
    getline(cin, r);
    int res = 0;

    for (int i = 0; i < r.size(); i++) {
        if (r[i] >= 'A' && r[i] <= 'Z') {
            res++;
        }
    }

    cout << res;
    return 0;
}