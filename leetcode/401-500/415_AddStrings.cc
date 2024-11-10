class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, n1 = 0, n2 = 0, n3 = 0, i = num1.size() - 1,
            j = num2.size() - 1;
        string res;

        while (i >= 0 || j >= 0) {
            n1 = i >= 0 ? (int)(num1[i--] - '0') : 0;
            n2 = j >= 0 ? (int)(num2[j--] - '0') : 0;
            n3 = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            res.insert(res.begin(), n3 + '0'); // EPoint: not push_back
        }
        /**
        for (i = num1.size() - 1, j = num2.size() - 1; i >= 0, j >= 0;
            i--, j--) {
            n1 = num1[i] - '0';
            n2 = num2[j] - '0';
            n3 = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
             res.push_back(n3 + '0');
        }
         

        while (i >= 0) res.insert(res.begin(), num1[i--]);
        while (j >= 0) res.insert(res.begin(), num2[j--]);
        */
        return carry ? "1" + res : res; // EPoint: carry judge.
    }
};