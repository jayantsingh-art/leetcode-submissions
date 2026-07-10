class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int low = 0, high = 0, ans = 0;

        while(high < fruits.size()) {
            mp[fruits[high]]++;

            while(mp.size() > 2) {
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0) {
                    mp.erase(fruits[low]);
                }
                low++;
            }
            ans = max(ans, high-low+1);
            high++;
        }

        return ans;
    }
};