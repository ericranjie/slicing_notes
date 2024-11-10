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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy, *cur = head;

        while (cur && cur->next) {
            ListNode *tmp = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            cur->next = tmp;
            pre = cur;
            cur = cur->next;
        }

        return dummy->next;
    }
};