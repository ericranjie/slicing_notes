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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head; // EPoint
        ListNode *cur = head->next, *pre = head;

        while (cur) {
            while (cur && cur->val == pre->val)
                cur = cur->next;
            pre->next = cur;
            pre = cur;
            if (cur) cur = cur->next;
        }

        return head;
    }
};