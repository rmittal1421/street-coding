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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        if (!head->next) return false;
        if (head->next == head) return true;
        
        ListNode* fastMoving = head->next;
        ListNode* slowMoving = head;

        while (fastMoving != NULL) {
            if (fastMoving->next != slowMoving) {
                if (fastMoving->next != NULL) {
                    if (fastMoving->next->next != slowMoving) {
                        fastMoving = fastMoving->next->next;
                        slowMoving = slowMoving->next;
                    }
                    else return true;
                } else return false;
            } else return true;
        }
        return false;
        
    }
};