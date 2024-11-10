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
    bool isPalindrome(ListNode* head) {
        ListNode *s = head, *f = head, *d = new ListNode(-1, head);

        while (f && f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }

        d->next = s->next;
        s->next = nullptr;
        f = d->next;

        while (f && f->next) {
            ListNode *t = f->next; // EPoint: template must remember.
            f->next = t->next;
            t->next = d->next;
            d->next = t;
        }

        s = head;
        f = d->next;
        while (s && f) {
            if (s->val != f->val) return false;
            s = s->next;
            f = f->next;
        }
        return true;
    }
};