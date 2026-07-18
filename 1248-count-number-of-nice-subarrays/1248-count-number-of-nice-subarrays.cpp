class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }

    int atMost(vector<int> nums, int k) {
        int n = nums.size();
        int ans = 0, left = 0, right = 0, odds = 0;

        while(right < n) {
            if(nums[right] % 2) {
                odds++;
            }
            while(odds > k) {
                if(nums[left] % 2) {
                    odds--;
                }
                left++;
            }
            ans += right-left+1;
            right++;
        }

        return ans;
    }
};