class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        ans[0] = nums[0];
        ans[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            ans[i] = max(nums[i] + ans[i-2], ans[i-1]);
        }

        return ans[n-1];
    }
};