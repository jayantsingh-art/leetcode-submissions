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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        deque<TreeNode*> dq;
        vector<vector<int>> ans;
        bool leftToRight = true;
        dq.push_front(root);

        while(!dq.empty()) {
            int size = dq.size();
            vector<int> level;

            while(size--) {
                if(leftToRight) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    level.push_back(node->val);

                    if(node->left) {
                        dq.push_back(node->left);
                    }
                    if(node->right) {
                        dq.push_back(node->right);
                    }
                } else {
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    level.push_back(node->val);

                    if(node->right) {
                        dq.push_front(node->right);
                    }
                    if(node->left) {
                        dq.push_front(node->left);
                    }
                }
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};