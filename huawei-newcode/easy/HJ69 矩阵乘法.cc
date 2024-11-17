#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y, z;
    int t;
    cin >> x >> y >> z;
    vector<vector<int>> a(x, vector<int>(y, 0)),
        b(y, vector<int>(z, 0)),
        c(x, vector<int>(z, 0));

    // Step-1: Input matrix a, b;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> t;
            a[i][j] = t;
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < z; j++) {
            cin >> t;
            b[i][j] = t;
        }
    }

    // Step-2: Multiple matrix c;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            for (int k = 0; k < y; k++)
                c[i][j] += a[i][k] * b[k][j];
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}