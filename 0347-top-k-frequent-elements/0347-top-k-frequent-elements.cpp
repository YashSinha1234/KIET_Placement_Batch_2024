class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> freqPairs;
        for (auto it : freq) {
            freqPairs.push_back({it.second, it.first});
        }
        sort(freqPairs.begin(), freqPairs.end());
        vector<int> result;
        for (auto it : freqPairs) {
            result.push_back(it.second);
        }
        reverse(result.begin(), result.end());
        vector<int> finalResult(result.begin(), result.begin() + k);
        return finalResult;
    }
};