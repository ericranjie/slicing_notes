/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> res;
        ListNode *s = head, *f = head, *t = nullptr;
        int n = 0, quo = 0, rem = 0; // quotient, remainder
        int i = 0, j = 0;

        while (s) {
            ++n;
            s = s->next;
        }
        s = head; // EPoint

        quo = n / k;
        rem = n % k;

        for (i = 0; i < k; i++) {
            for (j = 0; j < quo + (rem == 0 ? 0 : 1) - 1; j++) {
                if (f) f = f->next;
            }
            t = s;
            if (s && f) s = f->next; 
            if (f) f->next = nullptr;
            res.push_back(t);
            f = s;
            if (rem > 0) --rem; // EPoint
        }
        return res;
    }
};