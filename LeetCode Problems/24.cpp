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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* f = head;
        ListNode* s = head->next;
        ListNode* it = head; 
        while (f!=NULL&&s!=NULL) {
            f->next = s->next;
            s->next = f;
            f = f->next;
            if (head == it) {
                head = s;
                it = head;
            }
            else it->next = s;
            it = s->next;
            if (f != NULL) s = f->next;
        }
        return head;
    }
};
