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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        std::vector<ListNode*> vec;
        ListNode* current = head;
        while (current != NULL) {
            vec.push_back (current);
            current = current->next;
        }
        return vec[vec.size()/2];
    }
};