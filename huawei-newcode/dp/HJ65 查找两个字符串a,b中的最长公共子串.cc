#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
abcdefghijklmnop
abcsafjklmnopqrstuvw
*/

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    vector<vector<int>> dp(a.size(),
        vector<int>(b.size(), 0));

    // map<int, vector<string>> mp;
    int mx = 0;
    string res;
    int nearest;
    if (a.size() < b.size()) { // POE:
        nearest = a.size(); // POE: shortest
    } else {
        nearest = b.size();
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                if (i >= 1 && j >= 1) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    string tmp;
                    if (i - dp[i][j] + 1 >= 0) // POE:
                        tmp = a.substr(i - dp[i][j] + 1, dp[i][j]); // POE: + 1
                    // mp[dp[i][j]].push_back(tmp);
                    // cout << tmp << endl;

                    // mx = max(mx, dp[i][j]);
                    if (dp[i][j] > mx) {
                        mx = dp[i][j];
                        if (a.size() < b.size()) {
                            nearest = i;
                        } else {
                            nearest = j;
                        }
                        // cout << nearest << "-" << i << " " << j << " " << tmp << endl;
                        res = tmp;
                    } else if (dp[i][j] == mx) {
                        // cout << nearest << " " << i << " " << j << " " << tmp << endl;
                        if (nearest > i && a.size() < b.size()) {
                            nearest = i;
                            res = tmp;
                        } else if (nearest > j && a.size() > b.size()) {
                            nearest = j;
                            res = tmp;
                        }
                    }
                } else if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }
    }

    cout << res;
    // cout << mx;
    // auto it = mp.rbegin();
    // cout << (it->second)[0];
    return 0;
}
// efgyiffxoonftmmvd
// exwzdcwjsttuhsxrcpzplpnfqxqsqtlfctdkgacejitayoafucmfxxhkxyixxykndchyjc

// nvlrzqcjltmrejybjeshffenvkeqtbsnlocoyaokdpuxutrsmcmoearsgttgyyucgzgcnurfbubgvbwpyslaeykqhaaveqxijc
// wkigrnngxehuiwxrextitnmjykimyhcbxildpnmrfgcnevjyvwzwuzrwvlomnlogbptornsybimbtnyhlmfecscmojrxekqmj
// llmgzeesikliqfeguiiivvx
// bzgzrfsgysrfnryfjuzzrdwvgrdgntuctylbdsrfxftslxvdnhaojykvsbvrfabgqiyggtducdglegjouhmwgicbtfxwvxoetxudfoaddjeerrxlvpafsksfruxkdzzbagcetfutbiallwgeevkfrvbnqzyescpvpdvbsqfjlncfyyflqitiqjpajatascusgvojebudfguatzvfakovjtiguheizezhljdl


// 64 位输出请用 printf("%lld")