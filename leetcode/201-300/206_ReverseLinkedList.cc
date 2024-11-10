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
    ListNode* reverseList(ListNode* head) {
/*
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head->next, *pre = head;

        dummy->next = head;
        while (cur && cur->next) {
            pre = pre->next;
            cur->next = dummy->next;
            dummy->next = cur;
            
            // pre->next = cur->next;
            cur = pre->next;
        }

        return dummy->next;
*/
        // Iterative Solution
        ListNode *tmp, *nhead = nullptr;

        while (head) {
            tmp = head->next;
            head->next = nhead;
            nhead = head;
            head = tmp;
        }

        return nhead;
    }
};