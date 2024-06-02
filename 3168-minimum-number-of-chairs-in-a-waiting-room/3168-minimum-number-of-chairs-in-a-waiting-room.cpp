class Solution {
public:
    int cnt = 0;
    int result = 0;
    int minimumChairs(string s) {
        for(auto it : s) {
            if(it == 'E') {
                cnt++;
                result = max(result, cnt);
            }
            else cnt--;
        }
        return result;
    }
};