class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> hashmap;
        for(int i = 0; i < s.length(); i++) {
            hashmap[s[i]]++;
        }
        int result = 0;
        bool flag = false;
        for(auto it: hashmap) {
            if(it.second % 2 == 0) result += it.second;
            else {
                result += it.second - 1;
                flag = true;
            }
        }
        if(flag) return result + 1;
        else return result;
    }
};