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
    bool isValid;
    long prevVal;
    bool isValidBST(TreeNode* root) {
        isValid = true;
        prevVal = LONG_MIN;

        DFS(root);

        return isValid;
    }

    void DFS(TreeNode* root) {
        if(!root) return;

        DFS(root->left);

        if(prevVal >= root->val) {
            isValid = false;
            return;
        }

        prevVal = root->val;
        DFS(root->right);
    }
};