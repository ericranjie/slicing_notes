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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // EPoint: must have this line.
        ListNode *dummy = new ListNode(-1, head), *s = dummy,
            *f = dummy;

        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode *t = s->next;
        s->next = nullptr;
        return Merge(sortList(head), sortList(t));
    }

    /** My Deprecated Solution:
      *
    ListNode* MergeSort(ListNode *left, ListNode *right) {
        if (left == right) return left;
        ListNode *dummy = new ListNode(-1, left), *s = dummy,
            *f = dummy, *h1 = nullptr, *h2 = nullptr;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }

        // Need swap
        if (s->next == f && s->val > f->val) {
            dummy->next = f;
            f->next = s;
            return dummy->next;
        }

        h1 = MergeSort(left, s);
        h2 = MergeSort(s->next, right);
        return Merge(h1, h2);
    }
    */
    ListNode* Merge(ListNode *h1, ListNode *h2) {
        ListNode *d = new ListNode(-1), *cur = d;
        
        while (h1 && h2) {
            if (h1->val < h2->val) {
                cur->next = h1;
                h1 = h1->next;
            } else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }

        cur->next = h1 ? h1 : h2;
        return d->next;
    }
};