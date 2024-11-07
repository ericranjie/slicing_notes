#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// abandon:
// 1. community-solution-failed;
// 2. doubt-test-case-error;


static bool veri_ip(string p);
static bool veri_mask(string m);

static void clas_ip(vector<int> p, vector<int> &res); // classify-ip

static void veri(string a, vector<int> &res);


int main() {
    string t;
    vector<string> v;
    vector<int> res(7, 0);

    while (getline(cin, t)) {
        v.push_back(t);
        // cout << t << endl;
        veri(t, res);
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}

static void clas_ip(vector<int> p, vector<int> &res) {
    if (p[0] >= 1 && p[0] <= 126) { // A
        ++res[0];
        if (p[0] == 10) {
            ++res[6];
        }
    } else if (p[0] >= 128 && p[0] <= 191) { // B
        ++res[1];
        if (p[0] == 172 && p[1] >= 16 && p[1] <= 32) {
            ++res[6];
        }
    } else if (p[0] >= 192 && p[0] <= 223) { // C
        ++res[2];
        if (p[0] == 192 && p[1] == 168) {
            ++res[6];
        }
    } else if (p[0] >= 224 && p[0] <= 239) { // D
        ++res[3];
    } else if (p[0] >= 240 && p[0] <= 255) { // D
        ++res[4];
    }
    return;
}

static bool veri_ip(string p, vector<int> &res) {
    int nd = 0; // number-of-dot
    vector<int> vp; // ip-vector
    int n = 0;
    bool flip_dot = false; // current-is-dot-or-not
    for (int i = 0; i < p.size(); i++) {
        // cout << i << " " << m[i] << endl;
        if (p[i] == '.') {
            if (flip_dot == true) { // cannot-dot-continue
                // cout << "f2" << endl;
                return false;
            }
            ++nd;
            if (n < 0 || n > 255) {
                // cout << "f1" << endl;
                return false;
            }
            vp.push_back(n);
            // cout << n << " ";
            n = 0; // reset
            flip_dot = true;
            continue;
        } else {
            flip_dot = false;
        }
        n *= 10;
        n += p[i] - '0';
    }
    vp.push_back(n); // POE: remember-this

    clas_ip(vp, res);

    return true;
}

static bool veri_mask(string m) {
    // 128 - 192 - 224 - 240 - 248 - 252 - 254 - 255
    int nd = 0; // number-of-dot
    vector<int> vm;
    int n = 0;
    for (int i = 0; i < m.size(); i++) {
        // cout << i << " " << m[i] << endl;
        if (m[i] == '.') {
            ++nd;
            vm.push_back(n);
            // cout << n << " ";
            n = 0; // reset
            continue;
        }
        n *= 10;
        n += m[i] - '0';
    }
    vm.push_back(n); // POE: remember-this
    // cout << n << endl;

    if (vm.size() != 4 || nd != 3) {
        return false; // guard:
    }

    if ((vm[0] == 255 && vm[1] == 255 && vm[2] == 255 && vm[3] == 255) ||
        (vm[0] == 0 && vm[1] == 0 && vm[2] == 0 && vm[3] == 0)) {
        return false; // guard: POE:
    }

    set<int> st = {128, 192, 224, 240, 248, 252, 254}; // 255-out
    bool split = false; // 1-0-split
    for (int i = 0; i < vm.size(); i++) {
        if (split && vm[i] != 0) {
            // cout << "f2" << endl;
            return false;
        }
        if (!split) {
            if (vm[i] != 255 && !st.count(vm[i]) &&
                vm[i] != 0) { // POE: must-need-this
                // cout << "f1 " << vm[i] << endl;
                return false;
            }
        }
        if (st.count(vm[i])) { // split-appear
            split = true;
        }
    }
    // cout << "true" << endl;
    return true;
}

static void veri(string a, vector<int> &res) { // verify
    int t = a.find_first_of("~"); // tilde-index
    if (t == string::npos) {
        return; // guard:
    }
    string ip = a.substr(0, t);
    string mask = a.substr(t + 1, a.size() - t);
    // cout << ip << " " << mask << endl;
    if (!veri_mask(mask)) { // POE: guard
        ++res[5];
        return;
    }

    if (!veri_ip(ip, res)) { // POE:
        ++res[5];
        // cout << res[5] << endl;
    }

    return;
}

// 42.53.252.112~255.0.0.0      a
// 166.237.7.68~255.0.0.0           b
// 136.3.73.64~255.255.0.0          b
// 204.29.136.133~255.255.0.245 w
// 195.30.208.94~255.255.0.213 w
// 154.253.86.183~255.200.255.0 w
// 94.164.187.131~255.255.0.0   a
// 167.79.164.186~255.0.0.0         b
// 194.172.2.64~255.255.0.0
// 210.212.79.137~255.255.255.42 w
// 143.151.137.40~255.255.255.255   bw
// 184.145.79.157~255.0.0.0         b
// 100.214.131.51~255.255.255.255 aw
// 233.10.182.98~255.0.0.125 w
// 99.184.165.228~255.0.0.82 w
// 92.20.159.86~255.0.0.0       a
// 198.198.174.83~255.0.0.0
// 17.158.122.89~255.255.75.255 w
// 149.253.103.237~255.0.26.0 w
// 91.243.182.7~255.0.0.0       a
// 36.76.55.4~255.255.255.255   aw
// 126.54.86.143~255.0.0.0      a

// 5 4 2 0 0 11 0

// 225.240.129.203~255.110.255.255  w
// 183.181.49.4~255.0.0.0
// 172.177.113.45~255.0.0.0
// 176.134.46.246~255.0.0.0
// 153.63.21.56~255.255.58.255      w
// 23.135.167.228~255.0.0.0
// 204.58.47.149~255.0.0.0
// 113.33.181.46~255.255.255.0
// 73.245.52.119~255.255.154.0      w -
// 23.214.47.71~255.0.0.0
// 139.124.188.91~255.255.255.100   w -
// 142.94.192.197~255.0.0.0
// 53.173.252.202~255.0.0.0
// 127.201.56.50~255.255.111.255    w
// 118.251.84.111~255.0.0.0
// 130.27.73.170~255.0.0.0
// 253.237.54.56~255.86.0.0         w -
// 64.189.222.111~255.255.255.139   w -
// 148.77.44.147~255.0.0.0
// 59.213.5.253~255.255.0.0
// 3.52.119.131~255.255.0.0
// 213.208.164.145~255.255.0.0
// 24.22.21.206~255.255.90.255      w
// 89.43.34.31~255.0.0.0
// 9.64.214.75~255.0.0.0
// 110.156.20.173~255.153.0.0       w -
// 71.183.242.53~255.255.0.0
// 119.152.129.100~255.0.0.0
// 38.187.119.201~255.0.0.0
// 73.81.221.180~255.255.255.255    w
// 73.198.13.199~255.0.15.0         w
// 99.42.142.145~255.255.255.0
// 196.121.115.160~255.0.0.0
// 226.30.29.206~255.0.0.0
// 244.248.31.171~255.255.255.255   w
// 59.116.159.246~255.0.0.0
// 121.124.37.157~255.0.0.226       w
// 103.42.94.71~255.255.0.0
// 125.88.217.249~255.255.74.255    w
// 73.44.250.101~255.255.255.0

// 16 6 3 1 0 13 0

// 64 位输出请用 printf("%lld")


#if 0
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

bool judge_ip(string ip){
    int j = 0;
    istringstream iss(ip);
    string seg;
    while(getline(iss,seg,'.'))
        if(++j > 4 || seg.empty() || stoi(seg) > 255)
            return false;
    return j == 4;
}

bool is_private(string ip){
    istringstream iss(ip);
    string seg;
    vector<int> v;
    while(getline(iss,seg,'.')) v.push_back(stoi(seg));
    if(v[0] == 10) return true;
    if(v[0] == 172 && (v[1] >= 16 && v[1] <= 31)) return true;
    if(v[0] == 192 && v[1] == 168) return true;
    return false;
}

bool is_mask(string ip){
    istringstream iss(ip);
    string seg;
    unsigned b = 0;
    while(getline(iss,seg,'.')) b = (b << 8) + stoi(seg);
    if(!b) return false;
    b = ~b + 1;
    if(b == 1) return false;
    if((b & (b-1)) == 0) return true;
    return false;
}

int main(){
    string input;
    int a = 0,b = 0,c = 0,d = 0,e = 0,err = 0,p = 0;
    while(cin >> input){
        istringstream is(input);
        string add;
        vector<string> v;
        while(getline(is,add,'~')) v.push_back(add);
        if(!judge_ip(v[1]) || !is_mask(v[1])) err++;
        else{
            if(!judge_ip(v[0])) err++;
            else{
                int first = stoi(v[0].substr(0,v[0].find_first_of('.')));
                if(is_private(v[0])) p++;
                if(first > 0 && first <127) a++;
                else if(first > 127 && first <192) b++;
                else if(first > 191 && first <224) c++;
                else if(first > 223 && first <240) d++;
                else if(first > 239 && first <256) e++;
            }
        }
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << p << endl;
    return 0;
}
#endif