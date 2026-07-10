class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            int product = 1;
            for(int j = i; j < n; j++) {
                product *= nums[j];

                if(product < k) {
                    ans++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};