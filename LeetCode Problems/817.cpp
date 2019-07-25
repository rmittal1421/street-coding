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
    int numComponents (ListNode* head, vector<int>& G) {
        ListNode* current = head;
        int count = 0;

        if (head == NULL) return count;
        set<int> s;
        for (int x:G) s.insert (x); 

        int compSize = 0;
        while (current != NULL) {
            if (s.find(current->val) != s.end()) {
                compSize++;
            } else {
                if (compSize != 0) {
                    count++;
                    compSize = 0;
                }
            }
            current = current->next;
        }
        if (compSize!=0) count++;
        return count;
    }
};