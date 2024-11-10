class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) return false; // EPoint
        stack<char> t;
        int i = 0;
        bool res = true;
        
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
            } else {
                if (t.empty()) return false; // EPoint
                if ((s[i] == ')' && t.top() != '(')) return false; // EPoint
                if ((s[i] == ']' && t.top() != '[')) return false;
                if ((s[i] == '}' && t.top() != '{')) return false;
                t.pop(); // EPoint
            }
        }

        if (t.size() > 0) return false; // EPoint
        return true;
    }
};