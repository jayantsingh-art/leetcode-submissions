class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, maxArea = 0;

        while(left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, w * h);

            if(height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};