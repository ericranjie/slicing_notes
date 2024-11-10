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
        if (!head) return nullptr;
        if (head && !head->next) return head;

        ListNode *dummy = new ListNode(-1, head), *pre = dummy,
            *cur = head, *post = head->next;

        while (post) {
            if (cur->val != post->val) {
                pre = pre->next;
                cur = cur->next;
                post = post->next;
            } else {
                while (post && cur->val == post->val)
                    post = post->next;
                pre->next = post;
                cur = post;
                if (post) post = post->next;
            }
        }

        return dummy->next;
    }
};