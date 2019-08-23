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
    ListNode* insertionSortList(ListNode* head) {
        if (!(head&&head->next)) return head;
        ListNode* cr = head->next;
        while (cr) {
            ListNode* now = head;
            int sudo = cr->val;
            bool valSwap = false;
            
            while (now != cr->next) {
                if(now->val > sudo || valSwap) {
                    valSwap = true;
                    int temp = sudo;
                    sudo = now->val;
                    now->val = temp;
                }
                now = now->next;
            }
            cr = cr->next;
        }
        
        return head;
    }
};
