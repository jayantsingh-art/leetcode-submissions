/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return(DFS(root, targetSum));
    }

    bool DFS(TreeNode* root, int targetSum) {
        if(!root) return 0;

        if(!root->left && !root->right && root->val == targetSum) {
            return true;
        }

        return DFS(root->left, targetSum - root->val) || DFS(root->right, targetSum - root->val);
    }
};