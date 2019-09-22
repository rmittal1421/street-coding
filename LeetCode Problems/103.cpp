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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>(0);
        deque<TreeNode*> pf, pb;
        bool popFront = true;
        pf.push_back(root);
        
        vector<vector<int>> result;
        while(!pf.empty() || !pb.empty()) {
            vector<int> now;
            if(popFront) {
                while(!pf.empty()) {
                    TreeNode* f = pf.back();
                    if(f->right) pb.push_back(f->right);
                    if(f->left) pb.push_back(f->left);
                    now.push_back(f->val);
                    pf.pop_back();
                }
            } else {
                while(!pb.empty()) {
                    TreeNode* f = pb.back();
                    if(f->left) pf.push_back(f->left);
                    if(f->right) pf.push_back(f->right);
                    now.push_back(f->val);
                    pb.pop_back();
                }
            }
            reverse(now.begin(), now.end());
            popFront = !popFront;
            result.push_back(now);
        }
        
        return result;
    }
};
