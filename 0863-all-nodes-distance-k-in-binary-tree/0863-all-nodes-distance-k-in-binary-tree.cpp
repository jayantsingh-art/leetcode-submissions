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
        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, parent);
        unordered_set<TreeNode*> st;
        queue<TreeNode*> q;
        vector<int> ans;

        q.push(target);
        st.insert(target);

        while(!q.empty()) {
            int size = q.size();

            if(k == 0) break;

            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                cout << node->val << endl;

                if(node->left && !st.count(node->left)) {
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right && !st.count(node->right)) {
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(parent[node] && !st.count(parent[node])) {
                    q.push(parent[node]);
                    st.insert(parent[node]);
                }
            }
            k--;
        }

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }

    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(!root) return;
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