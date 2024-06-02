class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 1) {
            cout << s[0];
            return;
        }
        for(int i = 0; i <= s.size()/2 - 1; i++) swap(s[i], s[s.size() - i - 1]);
        for(int i = 0;  i <= s.size() - 1; i++) cout << s[i] << " ";
    }
};