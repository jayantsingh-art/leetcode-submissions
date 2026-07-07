class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMax = nums[0], prevMin = nums[0], ans = nums[0];
        
        //at every index, we track both maximum and minimum product ending at that index. The minimum is just as important as the maximum because it has the potential to become the maximum after encountering another negative number.
        for(int i = 1; i < nums.size(); i++) {

            // A negative number swaps the roles of max and min
            if(nums[i] < 0) {
                swap(prevMin, prevMax);
            }

            prevMax = max(nums[i], prevMax * nums[i]);
            prevMin = min(nums[i], prevMin * nums[i]);

            ans = max(ans, prevMax);
        }

        return ans;
    }
};