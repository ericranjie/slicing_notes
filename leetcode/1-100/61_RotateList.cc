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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode *s = head, *f = head, *d = new ListNode(-1, head);
        int i = 0, n = 0;

        while (f) { // EPoint: no f->next
            ++n;
            f = f->next;
        }
        f = head;

        for (i = 0; i < k % n; i++) {
            f = f->next;
        }

        while (f && f->next) {
            s = s->next;
            f = f->next;
        }
        
        f->next = d->next;
        d->next = s->next;
        s->next = nullptr;

        return d->next;
    }
};