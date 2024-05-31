class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long int, long long int> hashmap;
        long long ans = 0;
        for(auto num : nums1) {
            for(int i = 1; i <= sqrt(num); i++) {
                if(num % i == 0) {
                    hashmap[i]++;
                    if(i != num / i) hashmap[num / i]++;
                }
            }
        }
        for(auto num : nums2) {
            ans += hashmap[num * k];
        }
        return ans;
    }
};