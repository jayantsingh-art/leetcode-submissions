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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root, p, q);
    }

    TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root->val < p->val && root->val < q->val) {
            return DFS(root->right, p, q);
        }
        if(root->val > p->val && root->val > q->val) {
            return DFS(root->left, p, q);
        }

        return root;
    }
};