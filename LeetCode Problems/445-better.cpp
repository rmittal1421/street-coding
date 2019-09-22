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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* curr = l1;
        while(curr) s1.push(curr->val), curr = curr->next;
        curr = l2;
        while(curr) s2.push(curr->val), curr = curr->next;
        ListNode* head = NULL;
        int c = 0; //carryover
        while(!s1.empty() || !s2.empty()) {
            int f = 0, s = 0;
            if(!s1.empty()) f = s1.top(), s1.pop();
            if(!s2.empty()) s = s2.top(), s2.pop();
            
            int toAdd = f + s + c;
            if(toAdd >= 10) {
                c = 1;
                toAdd -= 10;
            } else c = 0;
            ListNode* temp = new ListNode(toAdd);
            temp->next = head;
            head = temp;
        }
        if(c > 0) {
            ListNode* temp = new ListNode(c);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
