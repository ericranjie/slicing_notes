#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
using namespace std;

// POE: think-complex
// void helper(string &t, int s, int e) {

//     return;
// }

// recite:

int main() {
    string r, t, res;
    getline(cin, r);

#if 1
    bool already_block = false;
    string w; // word
    for (auto it = r.begin(); it != r.end(); it++) {
        if (0 != isalpha(*it)) { // is-alpha POE:
            already_block = false;
            // t.push_back(*it);
            // t = *it + t;
            w.push_back(*it);
            // cout << w << " : " << endl;
        } else { // is-not-alpha
            if (already_block == false) {
                // t.push_back(' ');
                t = w + " " + t;
                // cout << t << " " << endl;
                already_block = true;
                w.resize(0);
            }
        }
    }
    t = w + " " + t;
    cout << t << endl;
#endif

    // string::size_type sep;
    // int index = 0;
    // for (int i = 0; i < t.size(); ++i) {
    //     sep = t.find_first_of(" ", i);
    //     if (sep != string::npos) {
    //         // helper(i, i + sep - index);
    //     } else break;
    //     cout << sep << " " << index << " " << t.size() << endl;
    // }

    // cout << t << endl;

    return 0;
}
// wyZksmG XY ReXA Pedt mabjlFdGmJUseHz GzciYPmv OFKis SQzQAeQexsgy ZVrsqqSbHdQF AKPJECiP vOgIXvbuJTDnpPcCD GWlPWTGQSWyaZtxHd ydpT pHSeYKetXH RdBcHmggvESwIEWlBtYq H VdkLHvSGupDEFOfH BcWxbNOQOOYYhBNEz MAFjrzTFKWZOCGGZazCn Ef owSLRoGJXMWAR pLdQQWx ZSRXXCUOSetMNfSOnRk jDhskr WHBmEifhgEEBoT CJNtdFFM n 
// 64 位输出请用 printf("%lld")