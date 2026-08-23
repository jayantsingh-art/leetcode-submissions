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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return DFS(root, low, high);
    }

    int DFS(TreeNode* root, int low, int high) {
        if(!root) return 0;
        // cout << root->val << endl;
        if(root->val < low) {
            return DFS(root->right, low, high);
        }

        if(root->val > high) {
            return DFS(root->left, low, high);
        }

        return root->val + 
                DFS(root->left, low, high) + 
                DFS(root->right, low, high);
    }
};