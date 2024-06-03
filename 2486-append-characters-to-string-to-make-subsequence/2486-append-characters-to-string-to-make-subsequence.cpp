class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0, longestPrefix = 0;
        while(first <= s.length() && longestPrefix < t.length()) {
             if(s[first] == t[longestPrefix]) {
                 longestPrefix++;
                 first++;
             }
            else {
                first++;
            }
        }
        return t.length() - longestPrefix;
    }
};