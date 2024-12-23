#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<string> ndict = { // number dictionary
    "", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"
};

static vector<string> idict = { // index dictionary
    "元", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿"
};

// cheat-solution:
// need-reveal: complex
int main() {
    double d;
    cin >> d;
    string r = "人民币";
    string tmp;

    // Step-1: point right;
    int t = round(d * 100); // POE: round()
    int m = t % 10; // m: mod
    if (m != 0) { // POE: must-have-this
        tmp += ndict[m];
        tmp += "分";
    }
    r = tmp;
    tmp.resize(0); // reset-tmp
    t /= 10;

    m = t % 10;
    if (m != 0) { // POE: must-have-this
        tmp += ndict[m]; // POE:
        tmp += "角";
    }
    r = tmp + r;
    tmp.resize(0); // reset-tmp
    t /= 10; // remove-all-decimal


    // Step-2: point left;
    int i = 0;
    bool z = false; // z: 0-flag-flip
    while (t > 0) {
        m = t % 10;
        if ((i == 1 && m == 1) || (i == 5 && m == 1)) { // POE: 10
            r = idict[i] + r;
            z = false; // flip-flop
        } else if (i > 0 && z) {
            r = "零" + r;
        } else if (m == 0) {
            z = true;
        } else {
            r = ndict[m] + idict[i] + r;
            z = false; // flip-flop
        }
        t /= 10;
        ++i;
    }

    r = "人民币" + r;
    cout << r;
    return 0;
}

// 1.40 - 人民币壹元肆角 - w: 人民币壹元肆角分
// 0.29 - 人民币贰角玖分 - w: 人民币贰角捌分
// 5.07 - 人民币伍元柒分 - w: 人民币伍元角柒分