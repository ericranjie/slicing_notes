#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class VendingMachine {
  public:
    VendingMachine(string t);
    void Pay(string t);
    void Buy(string t);
    void CoinReturn(string t);
    void Query(string t);
    vector<string> goodname_;
    vector<int> goodprice_;
    vector<int> goodnum_;
    vector<int> cashnum_; // 1-2-5-10
    int remain_;
};

VendingMachine::VendingMachine(string t) {
    remain_ = 0;
    goodname_.push_back("A1"); goodprice_.push_back(2);
    goodname_.push_back("A2"); goodprice_.push_back(3);
    goodname_.push_back("A3"); goodprice_.push_back(4);
    goodname_.push_back("A4"); goodprice_.push_back(5);
    goodname_.push_back("A5"); goodprice_.push_back(8);
    goodname_.push_back("A6"); goodprice_.push_back(6);

    int s1 = 1, s2 = 0; // space1-2
    for (int i = 2; i < t.size(); i++) {
        if (t[i] == ' ') {
            s2 = i;
        }
    }
    string g = t.substr(s1 + 1, s2 - s1 - 1); // POE: goodcmd
    string c = t.substr(s2 + 1); // cashcmd

    int n = 0;
    int j = 0;
    for (int i = 0; i < g.size(); i++) {
        if (g[i] != '-') {
            n *= 10;
            n += g[i] - '0';
        } else {
            goodnum_.push_back(n);
            // cout << n << endl;
            n = 0; // reset
        }
    }
    goodnum_.push_back(n); // POE:
    // cout << n << endl;

    j = 0;
    n = 0;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] != '-') {
            n *= 10;
            n += c[i] - '0';
        } else {
            cashnum_.push_back(n);
            // cout << n << endl;
            n = 0; // reset
        }
    }
    cashnum_.push_back(n); // POE:
    // cout << n << endl;
    cout << "S001:Initialization is successful" << endl;
}

void VendingMachine::Pay(string t) {
    // guard-1: empty-goods
    bool empty = true;
    for (int i = 0 ; i < goodnum_.size(); i++) {
        if (goodnum_[i] > 0) {
            empty = false;
            break;
        }
    }
    if (empty) {
        cout << "E005:All the goods sold out" << endl;
        return;
    }

    int n = 0;
    for (int i = 2; i < t.size(); i++) { // POE:2
        n *= 10;
        n += t[i] - '0';
    }
    // guard-2: invalid-pay-coin
    if (n != 1 && n != 2 && n != 5 && n != 10) {
        cout << "E002:Denomination error" << endl;
        return;
    }

    // guard-3: low-cash
    int lowcash = cashnum_[0] + cashnum_[1] * 2;
    if (n != 1 && n != 2 && lowcash < n) {
        cout << "E003:Change is not enough, pay fail" << endl;
        return;
    }

    // success:
    remain_ += n;
    if (n == 1) cashnum_[0]++;
    else if (n == 2) cashnum_[1]++;
    else if (n == 5) cashnum_[2]++;
    else if (n == 10) cashnum_[3]++; 
    cout << "S002:Pay success,balance=" << remain_ << endl;
    return;
}

void VendingMachine::Buy(string t) {
    string good = t.substr(2);
    // guard-1: invalid-good-name
    bool valid = false;
    int goodidx = 0;
    for (int i = 0; i < goodname_.size(); i++) {
        if (good == goodname_[i]) {
            valid = true;
            goodidx = i;
            break;
        }
    }
    if (!valid) {
        cout << "E006:Goods does not exist" << endl;
        return;
    }

    // guard-2: empty-goods
    if (goodnum_[goodidx] <= 0) {
        cout << "E007:The goods sold out" << endl;
        return;
    }

    // guard-3: lack-cash
    // int remaincash = cashnum_[0] + cashnum_[1] * 2 +
    //     cashnum_[2] * 5 + cashnum_[3] * 10;
    if (remain_ < goodprice_[goodidx]) {
        cout << "E008:Lack of balance" << endl;
        return;
    }

    // success:
    remain_ -= goodprice_[goodidx];
    cout << "S003:Buy success,balance=" << remain_ << endl;
    return;
}

void VendingMachine::CoinReturn(string t) {
    // guard-1: zero-remain-cash
    // int remaincash = cashnum_[0] + cashnum_[1] * 2 +
    //     cashnum_[2] * 5 + cashnum_[3] * 10;
    // cout << remaincash << endl;
    if (remain_ == 0) {
        cout << "E009:Work failure" << endl;
        return;
    }

    // success: greedy-algorithm
    int n1 = 0, n2 = 0, n5 = 0, n10 = 0;
    while (remain_ > 0) {
        if (remain_ >= 10 && cashnum_[3] > 0) {
            remain_ -= 10;
            cashnum_[3]--;
            n10++;
        } else if (remain_ >= 5 && cashnum_[2] > 0) {
            remain_ -= 5;
            cashnum_[2]--;
            n5++;
        } else if (remain_ >= 2 && cashnum_[1] > 0) {
            remain_ -= 2;
            cashnum_[1]--;
            n2++;
        } else if (remain_ >= 1 && cashnum_[0] > 0) {
            remain_ -= 1;
            cashnum_[0]--;
            n1++;
        }
    }

    cout << "1 yuan coin number=" << n1 << endl;
    cout << "2 yuan coin number=" << n2 << endl;
    cout << "5 yuan coin number=" << n5 << endl;
    cout << "10 yuan coin number=" << n10 << endl;
    return;
}

void VendingMachine::Query(string t) {
    if (t.size() != 3 || (t.size() == 3 && 
        (t[2] - '0' != 0 && t[2] - '0' != 1))) {
        cout << "E010:Parameter error" << endl;
        return;
    }
    int category = t[2] - '0';
    if (category == 0) { // query: goodbox
        int mx = 0;
        int mxi = 0;
        vector<int> v = goodnum_;
        for (int i = 0; i < 6; i++) {
            for (int j = 5; j >= 0; j--) {
                if (v[j] == -1) {
                    continue;
                }
                if (mx <= v[j]) {
                    mxi = j;
                    mx = v[j];
                }
            }
            cout << goodname_[mxi] << " " <<
                goodprice_[mxi] << " " <<
                goodnum_[mxi] << endl;
            v[mxi] = -1; // mark-visited
            mx = 0; // reset
        }
    } else if (category == 1) { // query: cashbox
        cout << "1 yuan coin number=" << cashnum_[0] << endl;
        cout << "2 yuan coin number=" << cashnum_[1] << endl;
        cout << "5 yuan coin number=" << cashnum_[2] << endl;
        cout << "10 yuan coin number=" << cashnum_[3] << endl;
    }
    return;
}

int main() {
    string t;
    getline(cin, t);

    int s = 0; // space-index
    int p = 0; // prev-index
    vector<string> cmd;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == ';') {
            s = i;
            cmd.push_back(t.substr(p, s - p));
            p = i + 1;
            ++i;
        }
    }
    cmd.push_back(t.substr(p, t.size() - p));

    VendingMachine vm(cmd[0]);
    for (int i = 1; i < cmd.size(); i++) {
        string c = cmd[i];
        if (c[0] == 'q') {
            // cout << c;
            vm.Query(c);
        } else if (c[0] == 'c') {
            vm.CoinReturn(c);
        } else if (c[0] == 'b') {
            vm.Buy(c);
        } else if (c[0] == 'p') {
            vm.Pay(c);
        }
    }

    return 0;
}
// r 18-4-16-3-7-26 11-1-11-4;q1;c;c;q1;p 1;c;p 1;p 10;
// S001:Initialization is successful
// E010:Parameter error
// E009:Work failure
// E009:Work failure
// E010:Parameter error
// S002:Pay success,balance=1
// 1 yuan coin number=1
// 2 yuan coin number=0
// 5 yuan coin number=0
// 10 yuan coin number=0
// S002:Pay success,balance=1
// 64 位输出请用 printf("%lld")