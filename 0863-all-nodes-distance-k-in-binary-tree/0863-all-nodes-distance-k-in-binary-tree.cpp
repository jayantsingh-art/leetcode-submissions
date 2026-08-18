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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, parent);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        vector<int> ans;
        int dist = 0;

        q.push(target);
        visited.insert(target);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            if(dist == k) break;

            while(size--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent[node] && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            dist++;
        }

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }

    void buildParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
};