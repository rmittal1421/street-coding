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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* current = headA;
        std::set<ListNode*> s;
        while (current != NULL) {
            s.insert (current);
            current = current->next;
        } 
        current = headB;
        while (current != NULL) {
            if ((s.find(current)) != s.end()) return current;
            current =current->next;
        }
        return NULL;
    }
};
