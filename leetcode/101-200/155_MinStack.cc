class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if (t.empty() || val <= t.top()) // EPoint: must be <=
            t.push(val);

/** My Deprecated Solution:
        s.push(val);
        if (t.empty()) {
            t.push(val);
        } else {
            if (val < t.top()) {
                t.push(val);
            } else {
                vector<int> v;
                while ((!t.empty()) && (val > t.top())) {
                    //if (val > t.top()) {
                    //int i = t.top();
                    //v.push_back(i);
                    if (!t.empty()) t.pop();
                    //s}
                }
                t.push(val);
                
                while (v.size() > 0) {
                    int i = *(v.end() - 1);
                    t.push(i);
                    v.pop_back();
                }
            }
        }
*/
    }
    
    void pop() {
        int i = s.top();
        s.pop();
        if (i == t.top()) {
            t.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return t.top();
    }
private:
    stack<int> s, t;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */