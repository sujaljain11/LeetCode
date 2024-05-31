class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long int, long long int> hashmap;
        long long int ans = 0;
        for(auto num : nums2) hashmap[num * k]++;
        for(auto num : nums1) {
            for(int i = 1; i <= sqrt(num); i++) {
                if(num % i == 0) {
                    if(hashmap.find(i) != hashmap.end()) ans += hashmap[i];
                    
                    if(i != num / i && hashmap.find(num / i) != hashmap.end()) ans += hashmap[num / i];
                }
            }
        }
        return ans;
    }
};