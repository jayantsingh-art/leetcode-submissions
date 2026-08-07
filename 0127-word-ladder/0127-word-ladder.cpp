class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        int level = 1;
        if(s.find(endWord) == s.end()) return 0;
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
                        if(s.find(word) != s.end()) {
                            q.push(word);
                            s.erase(word);
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