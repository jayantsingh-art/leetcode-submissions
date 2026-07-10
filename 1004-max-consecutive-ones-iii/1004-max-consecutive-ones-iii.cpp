class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flips = 0, left = 0, ones = 0, ans = 0;

        for(int right = 0; right < nums.size(); right++) {
            ones++;
            if(nums[right] == 0) {
                flips++;
            }
            while(flips > k) {
                if(nums[left] == 0) {
                    flips--;
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }

        return ans;
    }
};