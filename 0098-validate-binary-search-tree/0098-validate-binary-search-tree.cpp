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
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        long prevVal = LONG_MIN;
        DFS(root, isValid, prevVal);

        return isValid;
    }

    void DFS(TreeNode* root, bool& isValid, long& prevVal) {
        if(!root) return;

        DFS(root->left, isValid, prevVal);

        if(prevVal >= root->val) {
            isValid = false;
            return;
        }
        prevVal = root->val;
        
        DFS(root->right, isValid, prevVal);
    }
};