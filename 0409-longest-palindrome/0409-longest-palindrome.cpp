class Solution {
public:
    int longestPalindrome(string s) {
        int oddFrequencyCount = 0;
        unordered_map<char, int> frequencyMap;
        for(auto character: s) {
            frequencyMap[character]++;
            if(frequencyMap[character] % 2 == 1) oddFrequencyCount ++;
            else oddFrequencyCount--;
        }
        if(oddFrequencyCount > 0) return s.length() - oddFrequencyCount + 1;
        else return s.length();
    }
};