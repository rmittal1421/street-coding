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
    ListNode* reverseListRecursive (ListNode* head, ListNode* prevNode = NULL) {
        if (head == NULL)	return prevNode;
        ListNode* now = head;
        head = head->next;
        now->next = prevNode;
        return reverseListRecursive (head, now);
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        //iterative approach
        /*
        ListNode* c1 = NULL;
        ListNode* c2 = head;
        
        while (c2 != NULL) {
            ListNode* temp = c2->next;
            c2->next = c1;
            c1 = c2;
            c2 = temp;
        }
        
        return c1;
        */
        
        //recursive approach
        return reverseListRecursive (head);
    }
};