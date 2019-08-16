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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int l = 0;
        vector<ListNode*> res;
        ListNode* current = root;
        while (current != NULL) {
            l++;
            current = current->next;
        }
        int conc = l/k;
        int over = l%k;
        current = root;
        int count = 0;
        int extra;
        ListNode* it = root;
        while (it!=NULL) {
            extra = (over>0) ? 1 : 0;
            if (count<(conc+extra-1)) {
                it = it->next;
                count++;
            } else {
                res.push_back (current);
                ListNode* temp = it->next;
                it->next = NULL;
                it = temp;
                current = it;
                over--;
                count=0;
            }
        }
        
        while (res.size()<k) res.push_back (current);
        return res;
    }
};
