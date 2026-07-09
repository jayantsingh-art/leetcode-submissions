class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int prefix = 0, ans = INT_MAX, j = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            while(prefix >= target) {
                prefix -= nums[j];
                ans = min(ans, i - j + 1);
                j++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};