/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reccur (vector<int> &vals, int s, int e) {
        if (s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* thisNode = new TreeNode (vals[mid]);
        thisNode->left = reccur (vals, s, mid-1);
        thisNode->right = reccur (vals, mid+1, e);
        return thisNode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vals;
        ListNode* current = head;
        while (current!=NULL) {
            vals.push_back (current->val);
            current = current->next;
        }
        return reccur (vals, 0, vals.size() - 1);
    }
};
