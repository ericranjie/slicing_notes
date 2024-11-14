#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
using namespace std;

// POE: think-complex
// recite:
int main() {
    string r, t; // raw-and-target;
    getline(cin, r);

    bool already_block = false;
    string w; // word
    for (auto it = r.begin(); it != r.end(); it++) {
        if (0 != isalpha(*it)) { // Is alpha; POE:
            already_block = false;
            w.push_back(*it);
        } else { // Is not alpha;
            if (already_block == false) {
                t = w + " " + t;
                already_block = true;
                w.resize(0);
            }
        }
    }
    t = w + " " + t;
    cout << t << endl;
    return 0;
}
// wyZksmG XY ReXA Pedt mabjlFdGmJUseHz GzciYPmv OFKis SQzQAeQexsgy ZVrsqqSbHdQF AKPJECiP vOgIXvbuJTDnpPcCD GWlPWTGQSWyaZtxHd ydpT pHSeYKetXH RdBcHmggvESwIEWlBtYq H VdkLHvSGupDEFOfH BcWxbNOQOOYYhBNEz MAFjrzTFKWZOCGGZazCn Ef owSLRoGJXMWAR pLdQQWx ZSRXXCUOSetMNfSOnRk jDhskr WHBmEifhgEEBoT CJNtdFFM n 