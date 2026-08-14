class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        vector<int> ans(n, -1);
        stack<int> st;

        for(int num : nums2) {
            while(!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        for(int i = 0; i < n; i++) {
                cout << nums1[i] << endl;
            if(mp.find(nums1[i]) != mp.end()) {
                ans[i] = mp[nums1[i]];
            }
        }

        return ans;
    }
};