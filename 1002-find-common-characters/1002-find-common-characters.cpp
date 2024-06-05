class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> currentCharacterCounts(26, 0), commonCharacterCounts(26, 0);
        string word1 = words[0];
        for(char word : word1) {
            commonCharacterCounts[word - 'a']++;
        }
        for(int i = 1; i <= words.size() - 1; i++) {
            fill(currentCharacterCounts.begin(), currentCharacterCounts.end(), 0);
            for(char word : words[i]) {
                currentCharacterCounts[word - 'a']++;
            }
            
            for(int i = 0; i <= 25; i++) {
                commonCharacterCounts[i] = min(commonCharacterCounts[i], currentCharacterCounts[i]);
            }
        }
        for(int i = 0; i <= 25; i++) {
                for(int commonCount = 0; commonCount < commonCharacterCounts[i]; commonCount++) {
                    result.push_back(string(1, i + 'a'));
                }
            }
        return result;
    }
};