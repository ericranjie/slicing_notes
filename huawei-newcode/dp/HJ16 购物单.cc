#include <iostream>
using namespace std;

int main() {
    int cash, m;
    int price[60], value[60], addi[60]; 
    int v, p, q;

    cin >> cash;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> price[i];
        cin >> value[i];
        cin >> addi[i];
        // cout << price[i] << value[i] << addi[i] << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")