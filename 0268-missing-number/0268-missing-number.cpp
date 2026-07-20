class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int numsTotal = n*(n+1)/2;

        for(int i = 0; i < n; i++) {
            numsTotal -= nums[i];
        }

        return numsTotal;
    }
};