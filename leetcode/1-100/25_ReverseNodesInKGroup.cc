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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy, *r = head, *cur = head;
        int i, j;

        while (cur) {
            i = 0;
            r = pre->next;
            while (i++ < k - 1 && r != nullptr) {
                r = r->next;
            }
            if (i < k - 1 || r == nullptr) break;

            cur = pre->next;
            j = 0;
            while (j++ < k - 1 && cur && cur->next) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }

            pre = cur;
        }

        return dummy->next;
    }
};