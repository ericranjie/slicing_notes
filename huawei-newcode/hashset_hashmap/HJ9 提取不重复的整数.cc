#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int a, res = 0;
    unordered_set<int> st;
    cin >> a;

    int cur = a, quo, mod;
    quo = cur / 10;
    mod = cur % 10;

    while (quo > 0) {
        if (!st.count(mod)) {
            st.insert(mod);
            res += mod;
            res *= 10;
        }
        cur = quo;
        quo = cur / 10;
        mod = cur % 10;
    }

    if (!st.count(mod)) {
        // st.insert(mod);
        res += mod;    
    } else {
        res /= 10; // POE:
    }

    cout << res;
    return 0;
}
// 64 位输出请用 printf("%lld")