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
        if (!head || !head->next) return head;
        
        ListNode* slow = NULL;
        ListNode* fast = head;
        bool sameExists = false;
        ListNode* approved = NULL;
        while (fast) {
            if (fast->next) {
                if (fast->val != fast->next->val) {
                    if (sameExists) fast = fast->next, sameExists = false;
                    else approved = fast, fast = fast->next;
                } 
                else {
                    sameExists = true;
                    fast = fast->next;
                }
            }
            else {
                if (!sameExists) approved = fast;
                fast = fast->next;
            }
            if (approved) {
                if (!slow) head = approved, slow = head;
                else slow->next = approved;
                slow = approved;
                approved = NULL;
            }
        }
        if (slow) {
            slow->next = fast;
            return head;
        }
        else return slow;
    }
};
