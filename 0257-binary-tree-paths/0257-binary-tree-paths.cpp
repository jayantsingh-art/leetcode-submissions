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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string> ans;

        DFS(root, path, ans);

        return ans;
    }

    void DFS(TreeNode* root, string path, vector<string>& ans) {
        if(!root) return;

        if(!path.empty()) path += "->";
        path += to_string(root->val);;

        if(!root->left && !root->right) {
            ans.push_back(path);
        }

        DFS(root->left, path, ans);
        DFS(root->right, path, ans);

    }
};