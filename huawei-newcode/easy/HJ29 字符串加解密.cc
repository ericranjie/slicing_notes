#include <iostream>
using namespace std;

int main() {
    string r, c; // Raw and Code;
    getline(cin, r);
    getline(cin, c);

    // Step-1: Encoding;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] >= '0' && r[i] <= '9') // Is number;
            r[i] = '0' + (((r[i] - '0') + 1) % 10);
        else if (r[i] >= 'a' && r[i] <= 'z') // Is lower alpha;
            r[i] = 'A' + (((r[i] - 'a') + 1) % 26);
        else if (r[i] >= 'A' && r[i] <= 'Z') // Is upper alpha;
            r[i] = 'a' + (((r[i] - 'A') + 1) % 26);
    }
    cout << r << endl;

    // Step-1: Decoding;
    r = c;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] >= '0' && r[i] <= '9') // Is number;
            r[i] = '0' + (((r[i] - '0') - 1 + 10) % 10);
        else if (r[i] >= 'a' && r[i] <= 'z') // Is lower alpha;
            r[i] = 'A' + (((r[i] - 'a') - 1 + 26) % 26);
        else if (r[i] >= 'A' && r[i] <= 'Z') // Is upper alpha;
            r[i] = 'a' + (((r[i] - 'A') - 1 + 26) % 26);
    }
    cout << r << endl;

    return 0;
}