class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, i = 0;

        for(int j = 0; j < s.size(); j++) {
            if(mp.find(s[j]) != mp.end()) {
                i = max(i, mp[s[j]]);
            }

            ans = max(ans, j-i+1);
            mp[s[j]] = j+1;
        }

        return ans;
    }
};