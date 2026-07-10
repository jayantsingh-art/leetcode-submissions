class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int prefix = 0, j = 0, ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            while(prefix >= target) {
                ans = min(ans, i-j+1);
                prefix -= nums[j];
                j++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};