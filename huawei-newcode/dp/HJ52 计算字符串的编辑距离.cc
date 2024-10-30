#include <iostream>
#include <vector>
using namespace std;

// abcdefg
// abcdef

// recite:
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int m = a.size(), n = b.size();
    // cout << a << " " << b << endl;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j - 1],
            min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
      }
    }
    cout << dp[m][n];
#if 0
    vector<vector<int>> dp(na, vector<int>(nb, 0));

    if (a[0] != b[0]) {
        dp[0][0] = 1;
        if (a[1] == b[0]) {
            dp[1][0] = 1;
        } else {
            dp[1][0] = 2;
        }
        if (a[0] == b[1]) {
            dp[0][1] = 1;
        } else {
            dp[0][1] = 2;
        }
    } else {
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[1][0] = 1;
    }

    for (int i = 2; i < na; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int j = 2; j < nb; j++) {
        dp[0][j] = dp[0][j - 1] + 1;
    }

    for (int i = 1; i < na; i++) {
        for (int j = 1; j < nb; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(dp[i - 1][j],
                    dp[i - 1][j - 1]), dp[i][j - 1]) + 1; // POE:
            }
        }
    }

    cout << dp[na - 1][nb - 1];
#endif
    return 0;    
}
// zikwvkijajpkaicihcffiemzexmwjjlyrylxcuoewdmpivudhmgkuodjaurazdjnlgtpwz
// wpnmubqfsnmapqpufmmsphqehjplwjkqspnnpywsvvjilxbcfsrygbelquaalenvkruyltiwqcpdrxgstywaja
// 73

// ucyfsmg
// zuixhuhyjgksyhqkjqxwylkoubykjxtcvkyqjpzgltbemmbmqibxxqpkgbvwbmjotixanvciibubglizmumcrjavakiygyuv
// 91

// xrufzxpeqmzxkxgltfkjdvmsklxywmmrojfsofxyuvihmswfmttjrldgdvtzjqdprwxnxeoklfzultwxbyteygsngrgnryfxyoefdnewpzeckodcrnsildzdsyiglcekqnrqffuwsbkvcwiyjpqlhmkesnl
// ucnogloymrueavqlhoadgeo
//141

// 64 位输出请用 printf("%lld")