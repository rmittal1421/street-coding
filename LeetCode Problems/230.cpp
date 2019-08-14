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
    void inorder(TreeNode* root, int& k, int& i, TreeNode* &target) {
        if(target) return;
        if(root == NULL) return;
        
        inorder(root->left, k, i, target);
        if(k == i) {
            target = root;
        } 
        i++;
        inorder(root->right, k, i, target);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int i = 1;
        TreeNode* target = NULL;
        inorder(root, k, i, target);
        return target->val;
    }
};
