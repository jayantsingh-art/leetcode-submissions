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
        return LCAHelper(root, p, q);
    }

    TreeNode* LCAHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val) {
            return LCAHelper(root->right, p, q);
        }
        if(root->val > p->val && root->val > q->val) {
            return LCAHelper(root->left, p, q);
        }

        return root;
    }
};