class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;

        while(i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }

        if(i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = n-1;
        while(j >= i && nums[j] <= nums[i-1]) {
            j--;
        }

        swap(nums[j], nums[i-1]);
        reverse(nums.begin() + i, nums.end());
    }
};