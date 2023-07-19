class Solution {
public:
    vector<int> twoSum(vector<int>& yash, int target) {
        vector<int> ans;
        
        for (int i = 0; i < yash.size(); i++) {
            for (int j = i + 1; j < yash.size(); j++) {
                if ((yash[i]+yash[j]) == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};