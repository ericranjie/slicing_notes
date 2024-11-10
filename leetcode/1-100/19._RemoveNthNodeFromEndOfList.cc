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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head, *dummy = new ListNode(-1, head), *pre = dummy;
        int cnt = n;
        
        while (fast && --cnt > 0) {
            fast = fast->next;
            //--cnt;
        }

        while (fast && fast->next) {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next;
        }
 
        pre->next = (n == 1) ? nullptr : slow->next; // EPoint: not fast.
        return dummy->next;
    }
};