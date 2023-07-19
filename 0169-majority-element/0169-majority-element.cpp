class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        int yash = nums.size()/2, sinha;
        for(auto i: mp){
            if(i.second>yash) sinha = i.first;
        }
        return sinha;
    }
};