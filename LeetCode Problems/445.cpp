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
    ListNode* generateNewNode (int value) {
        ListNode* newNode = new ListNode (value);
        return newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* curr = l1;
        while (curr != NULL) {
            s1.push(curr->val);
            curr = curr->next;
        }
        curr = l2;
        while (curr != NULL) {
            s2.push(curr->val);
            curr = curr->next;
        }

        int ans = 0;
        int carryOver = 0;
        while (!s1.empty() && !s2.empty()) {
            int a = s1.top();
            int b = s2.top();
            s1.pop();
            s2.pop();
            ListNode* newNode = generateNewNode ((a + b + carryOver)%10);
            carryOver = (a + b + carryOver)/10;
            newNode->next = curr;
            curr = newNode;
        }
        if (!s1.empty()) {
            while (!s1.empty()) {
                ListNode* newNode = generateNewNode ((s1.top() + carryOver)%10);
                carryOver = (s1.top() + carryOver)/10;
                s1.pop();
                newNode->next = curr;
                curr = newNode;
            }
        } else if (!s2.empty()) {
            while (!s2.empty()) {
                ListNode* newNode = generateNewNode ((s2.top() + carryOver)%10);
                carryOver = (s2.top() + carryOver)/10;
                s2.pop();
                newNode->next = curr;
                curr = newNode;
            }
        } 
        if (carryOver != 0) {
            ListNode* newNode = generateNewNode (carryOver);
            newNode->next = curr;
            curr = newNode;
        }
        return curr;
    }
};
