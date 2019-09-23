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
    bool dfs(TreeNode* &curr, TreeNode* &p, TreeNode* &q, TreeNode* &lc) {
        if(curr == NULL) return false;
        bool mid = (curr == p || curr == q) ? true : false;
        int counter = 0;
        bool left = dfs(curr->left, p, q, lc);
        bool right = dfs(curr->right, p, q, lc);
        
        if(mid) counter++;
        if(left) counter++;
        if(right) counter++;
        
        if(counter >= 2) lc = curr;
        return (counter > 0);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        TreeNode* lc = root;
        bool found = dfs(root, p, q, lc);
        if(found) return lc;
        else return NULL;
    }
};
