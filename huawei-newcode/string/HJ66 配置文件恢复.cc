#include <iostream>
#include <map>
using namespace std;

map<string, string> d = { // dictionary
    {"reset",               "reset what"},
    {"reset board",         "borad fault"},
    {"board add",           "where to add"},
    {"board delete",        "no board at all"},
    {"reboot backplane",    "impossible"},
    {"backplane abort",     "install first"}
};

void veri() { // verify

}

int main() {
    string t;
    while (getline(cin, t)) {

    }

    return 0;
}
// 64 位输出请用 printf("%lld")