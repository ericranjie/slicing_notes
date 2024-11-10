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
    void reorderList(ListNode* head) {
        /** My Deprecated Solution: judge odd or even.
        int cnt = 0;
          */
        ListNode *slow = head, *fast = head, *cur = nullptr,
            *pre = nullptr, *dummy = new ListNode(-1); // EPoint

        while (fast->next && fast->next->next) { // EPoint
            slow = slow->next;
            fast = fast->next->next;
        }

        cur = slow->next;
        dummy->next = cur;
        pre = cur;
        if (cur) cur = cur->next;
        while (cur) {
            ListNode *tmp = nullptr; // EPoint
            pre->next = cur->next;
            tmp = dummy->next;
            dummy->next = cur;
            cur->next = tmp;
            cur = pre->next;
        }

        slow->next = nullptr;

        cur = dummy->next;
        while (head && cur) { // EPoint: Autowire step.
            ListNode *tmp = head->next;
            head->next = cur;
            cur = cur->next;
            head->next->next = tmp;
            head = tmp;
        }
    }
};