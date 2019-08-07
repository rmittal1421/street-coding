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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* current = head;
        deque<int> dq;

        while (current != NULL) {
            dq.push_back (current->val);
            current = current->next;
        }
        while (!dq.empty()) {
            if (dq.back()!=dq.front()) return false;
            dq.pop_back();
            if (!dq.empty()) dq.pop_front();
        }
        return true;
    }
};
