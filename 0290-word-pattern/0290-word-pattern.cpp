class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        int count = 0, i = 0;

        map<string,char> mp;
        map<char,int> freq;

        while(ss >> word) {
            count++;
        }

        ss.clear();
        ss.str(s);

        if(count != pattern.length()) return false;

        while(ss >> word) {
            if(mp.count(word)) {
                if(mp[word] != pattern[i]) return false;
                freq[pattern[i++]]++;
            }
            else {
                if(freq[pattern[i]] != 0) return false;
                mp[word] = pattern[i];
                freq[pattern[i++]]++;
            } 
        }

        return true;
    }
};