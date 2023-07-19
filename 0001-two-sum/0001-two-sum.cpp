class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> yash;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int n = nums[i];
            int second_ele = target - n;
            if (yash.count(second_ele)) {
                return {yash[second_ele], i};
            }
            yash[n] = i;
        }
        return {};
    }
};