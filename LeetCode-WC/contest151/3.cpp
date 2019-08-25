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
    ListNode* removeZeroSumSublists(ListNode* head) {
        deque<int> s;
        ListNode* curr = head;
        if(!curr) return head;
        
        while(curr) {
            if(curr->val == 0) curr = curr->next;
            else {
                if(s.empty()) s.push_back(curr->val);
            else {
                int val = curr->val;
                int counter = 0;
                bool found = false;
                for(int i = s.size() - 1; i >= 0; i--) {
                    val += s[i];
                    counter++;
                    if(val == 0) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    s.push_back(curr->val);
                    //found nothing
                } else {
                    //found and delete as many
                    while(counter != 0) {
                        s.pop_back();
                        counter--;
                    }
                }
            }
            curr = curr->next;
            }
        }
        
        curr = head;
        if(s.empty()) head = NULL;
        while(!s.empty()) {
            int value = s.front();
            curr->val = value;
            if(s.size() == 1) curr->next = NULL;
            else curr = curr->next;
            s.pop_front();
        }
        
        return head;
    }
};