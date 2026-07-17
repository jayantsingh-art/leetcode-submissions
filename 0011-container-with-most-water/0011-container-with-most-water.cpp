class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, w = 0, h = 0;
        int maxArea = 0;

        while(left < right) {
            w = right - left;
            h = min(height[left], height[right]);

            maxArea = max(maxArea, w*h);

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};