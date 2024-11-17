#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int a, res = 0;
    unordered_set<int> st;
    cin >> a;

    int quo, mod;
    quo = a / 10; // quo: quotient
    mod = a % 10; // mod: module

    while (quo > 0) {
        if (!st.count(mod)) {
            st.insert(mod);
            res += mod;
            res *= 10;
        }
        a = quo;
        quo = a / 10;
        mod = a % 10;
    }

    if (!st.count(mod)) res += mod;    
    else res /= 10; // POE: need-divide-10

    cout << res;
    return 0;
}