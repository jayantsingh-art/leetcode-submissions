class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high) {
            int mid = low + (high - low) / 2;

            int requiredDays = 1;
            int currentWeight = 0;

            for(int weight : weights) {
                if(currentWeight + weight > mid) {
                    requiredDays++;
                    currentWeight = 0;
                }

                currentWeight += weight;
            }

            if(requiredDays <= days) {
                // Capacity works, try smaller
                high = mid;
            } else {
                // Capacity doesn't work, need larger
                low = mid + 1;
            }
        }

        return low;
    }
};