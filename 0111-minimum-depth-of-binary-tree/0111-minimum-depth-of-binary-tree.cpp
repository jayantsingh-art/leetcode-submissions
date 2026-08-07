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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 1});

        while(!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            if(!node->left && !node->right) return depth;

            if(node->left) {
                q.push({node->left, 1 + depth});
            }

            if(node->right) {
                q.push({node->right, 1 + depth});
            }
        }
        return 0;
    }
};