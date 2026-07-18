class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1, j = n-1;

        while(i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }

        if(i == 0) {
            return reverse(nums.begin(), nums.end());
        }

        while(j >= i && nums[j] <= nums[i-1]) {
            j--;
        }

        swap(nums[i-1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};