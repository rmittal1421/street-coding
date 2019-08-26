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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        int len = 0;
        ListNode* current = head;
        while (current) len++, current=current->next;
        current = head;
        if (len == n) {
            head = head->next;
            return head;
        }
        else {
            while (current) {
                if ((len-1) == n) {
                    current->next = current->next->next;
                    return head;
                }
                len--;
                current = current->next;
            }
        }
        return head;
    }
};
