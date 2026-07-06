class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            if(leftSum == sum - nums[i] - leftSum) {
                return i;
            } else {
                leftSum += nums[i];
            }
        }

        return -1;
    }
};