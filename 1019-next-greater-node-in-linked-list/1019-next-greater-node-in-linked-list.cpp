/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;
        stack<int> st;

        while(curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> ans(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};