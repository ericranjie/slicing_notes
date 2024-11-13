#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// recite:

// Card to number;
unordered_map<string, int> c2n = {
    {"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, 
    {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12},
    {"K", 13}
};

// Number to card;
unordered_map<int, string> n2c = {
    {1, "A"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"},
    {7, "7"}, {8, "8"}, {9, "9"}, {10, "10"}, {11, "J"}, {12, "Q"},
    {13, "K"}
};

const vector<char> Op = {'+', '-', '*', '/'};
 
int cal(int a, int b, int op) {
    if (op == 0) 
        return a + b;
    else if (op == 1) 
        return a - b;
    else if (op == 2) 
        return a * b;
    else
        return a / b;
}

bool cal24(vector<int>& a, vector<int>& op) { //这个数字顺序和符号顺序下能够达到24
    vector<int> b(a);
    for (int i = 0; i < 3; i++)
        b[i + 1] = cal(b[i], b[i + 1], op[i]);
    if (b[3] == 24) 
        return true;
    else 
        return false;
}

bool check(vector<int>& nums) {
    bool flag = false;
    vector<int> op(4);
    sort(nums.begin(), nums.end());
    do {
        for (int i = 0; i < 4 && !flag; i++) { // 枚举三个符号的所有情况
            op[0] = i;
            for (int j = 0; j < 4 && !flag; j++) {
                op[1] = j;
                for (int k = 0; k < 4 && !flag; k++) {
                    op[2] = k;
                    if (cal24(nums, op)) { // 符合条件就输出
                        for (int m = 0; m < 3; m++) {
                            cout << n2c[nums[m]] << Op[op[m]];
                        }
                        cout << n2c[nums[3]] << endl;
                        flag = true; // 找到了，准备跳出所有循环
                    }
                }
            }
        }
    } while(next_permutation(nums.begin(), nums.end()) && !flag); //枚举所有的数字顺序
    return flag;
}
 
int main() {
    vector<string> s(4);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    vector<int> nums(4);
    for (int i = 0; i < 4; i++) { 
        if (s[i] == "joker" || s[i] == "JOKER") { // Guard: joker and JOKER;
            cout << "ERROR" << endl;
            return 0;
        }
        nums[i] = c2n[s[i]]; // Char to number;
    }
    if (!check(nums)) // Main:
        cout << "NONE" << endl;
    return 0;
}
