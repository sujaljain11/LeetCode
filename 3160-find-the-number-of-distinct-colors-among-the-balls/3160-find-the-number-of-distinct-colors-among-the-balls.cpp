class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> valueCount;
        map<int, int> hashmap;
        vector<int> result;
        int uniqueCount = 0;
        for(auto query : queries) {
            int key = query[0], value = query[1];
            
            if(hashmap.count(key)) {
                int preValue = hashmap[key];
                valueCount[preValue]--;
                if(valueCount[preValue] == 0) uniqueCount--;
            }
            
            hashmap[key] = value;
            valueCount[value]++;
            if(valueCount[value] == 1) uniqueCount++;
            
            result.push_back(uniqueCount);
        }
        return result;
    }
};