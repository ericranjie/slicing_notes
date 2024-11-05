#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
};

void helper(int n, vector<int> v, int k) {
    ListNode *head = nullptr,
    *dummy = nullptr,
    *pre = nullptr;

    dummy = (ListNode *)malloc(sizeof(ListNode));
    dummy->m_nKey = -1;
    dummy->m_pNext = nullptr;

    pre = dummy;

    for (int i = 0; i < n; i++) {
        ListNode *cur = nullptr;
        cur = (ListNode *)malloc(sizeof(ListNode));
        cur->m_nKey = v[i];
        cur->m_pNext = nullptr;

        pre->m_pNext = cur;
        pre = pre->m_pNext;
    }

    ListNode *fast = dummy->m_pNext,
        *slow = dummy->m_pNext;

    // cout << "k: " << k << endl;
    while (k > 0) {
        k--;
        fast = fast->m_pNext;
    }

    while (fast && slow) {
        fast = fast->m_pNext;
        slow = slow->m_pNext;
    }

    cout << slow->m_nKey << endl;
    return;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> vs; // values
    vector<int> ns; // nums
    vector<int> ks; // ks

    int t;
    while (cin >> t) {
        ns.push_back(t);

        int n = t;
        vector<int> o;
        for (int i = 0; i < n; i++) {
            cin >> t;
            o.push_back(t);
        }
        vs.push_back(o);

        cin >> t;
        ks.push_back(t);
    }

    for (int i = 0; i < vs.size(); ++i) {
        helper(ns[i], vs[i], ks[i]);
    }

    return 0;
}