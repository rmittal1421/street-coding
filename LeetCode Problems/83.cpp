/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* now = head;
        ListNode* nxt = head->next;
        int val = now->val;

        while (nxt != NULL) {
            val = now->val;
            if (val == nxt->val) {
                nxt = nxt->next;
            } else {
                now->next = nxt;
                now = nxt;
                nxt = nxt->next;
            }
        }
        now->next = NULL;
        return head;
    }
};