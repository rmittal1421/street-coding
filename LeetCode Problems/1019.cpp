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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* ptr = head;
        vector<int> result;
        int count = 0;
        while(ptr) {
            result.push_back(ptr->val);
            count++;
            ptr = ptr->next;
        }
        
        int i = 0;
        stack<int> S;
        for(int i = 0; i < count; i++) {
            while(!S.empty() && result[S.top()] < result[i]) {
                result[S.top()] = result[i];
                S.pop();
            }
            S.push(i);
            
        }
        while(!S.empty()) {
            result[S.top()] = 0;
            S.pop();
        }
        return result;
    }
};
