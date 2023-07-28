class Solution {
public:
    void solve(int i,vector<int>&nums,set<vector<int>>&subsets, vector<int>&tmp,int n){
        // we traversed through all element
        if(i==n){
            sort(tmp.begin(),tmp.end());
            subsets.insert(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        solve(i+1,nums,subsets,tmp,n);
        // backtrack
        tmp.pop_back();
        solve(i+1,nums,subsets,tmp,n);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> subsets;
        vector<int> tmp;

        sort(nums.begin(),nums.end());

        solve(0,nums,subsets,tmp,nums.size());
        vector<vector<int>> distinctSubsets;
        // store all unique subsets
        for(auto st:subsets){
            distinctSubsets.push_back(st);
        }
        return distinctSubsets;
    }
};