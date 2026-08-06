class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        int level = 1;

        if(dict.find(endWord) == dict.end()) return 0;

        q.push(beginWord);

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                string word = q.front();
                q.pop();

                if(word == endWord) return level;

                for(int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(dict.find(word) != dict.end()) {
                            q.push(word);
                            // cout << q << endl;
                            dict.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            level++;
        }

        return 0;
    }
};