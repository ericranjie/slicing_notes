#include <iostream>
#include <vector>
using namespace std;

vector<string> vone = { // one-digit-vector (and-hundred)
    "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine"
};

vector<string> vten = { // ten-digit-vector
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
};

vector<string> vtwe = { // larger-than-twenty
    "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
    "eighty", "ninety"
};

// need-optimize-solution:
// need-reveal: complex
string trans(int o, int t, int h) { // one-ten-hundred-digit
    string r;

    if (h >= 1) { // POE: = 
        r += vone[h - 1]; // POE:
        r += " hundred "; // POE:
        if (t != 0 || o != 0) {
            r += "and ";
        }
    }
    if (t >= 2) { // POE: =
        r += vtwe[t - 2];
        r += " ";
    } else if (t == 1) {
        r += vten[o];
        // r += " ";
    }

    if (o >= 1 && t != 1) { // POE: t != 1
        r += vone[o - 1];
        r += " ";
    }

    // cout << "t: " << r << endl;
    return r;
}

int main() {
    long l;
    int d;
    cin >> l;
    d = (int)l;

    int t = d, c = 0; // temp-counter
    int m = 0; // mod
    int one = 0, two = 0, thr = 0; // 1-2-3-digit
    string res;
    bool batch = false; // need-batch
    while (t > 0) {
        ++c;
        m = t % 10;
        
        if (c >= 4 && c < 7 && batch) { // POE: < 7
            string tmp = trans(one, two, thr);
            one = 0; two = 0; thr = 0;
            if (c >= 4) // POE: must-have-this
                 tmp = "thousand " + tmp;
            res = tmp + res;
            batch = false;
        } else if (c >= 7) {
            string tmp = trans(one, two, thr);
            one = 0; two = 0; thr = 0;
            // tmp += " million "; // POE:
            res = tmp + res;
            batch = false;
        }
        
        if (c % 3 == 1) {
            one = m;
        } else if (c % 3 == 2) {
            two = m;
        } else if (c % 3 == 0) {
            thr = m;
            batch = true;
        }

        t /= 10;
    }

    string tmp = trans(one, two, thr);
    if (c == 7)
        tmp += "million ";
    res = tmp + res;

    cout << res;

    return 0;
}
// 11
// 100
// 1100
// 60830
// 64 位输出请用 printf("%lld")