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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* bubble = NULL;
        q.push(bubble);
        int maxLevel = 0;
        int maxSum = INT_MIN;
        int currentLevel = 0;
        int sum = 0;
        while(!q.empty()) {
            TreeNode* c = q.front();
            if(c) {
                q.pop();
                sum += c->val;
                if(c->left) q.push(c->left);
                if(c->right) q.push(c->right);
            } else {
                currentLevel++;
                if(sum > maxSum) {
                    maxSum = sum;
                    maxLevel = currentLevel;
                }
                q.pop();
                if(!q.empty() && q.front()) q.push(bubble);
                sum = 0;
            }
        }
        return maxLevel;
    }
};