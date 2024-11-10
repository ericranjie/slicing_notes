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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy, *cur, *tmp;
        int i = 0;

        for (i = 0; i < left - 1; i++) { // EPoint: left - 1
            pre = pre->next;
        }
        cur = pre->next;

        for (i = 0; i < right - left; i++) {
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next; // EPoint
            pre->next = tmp;
        }

        return dummy->next;
    }
};