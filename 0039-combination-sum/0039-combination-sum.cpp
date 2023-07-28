class Solution {
public:
    void findStuff(vector<int> &candidates, int target, vector<int> ds, int idx, vector<vector<int>> &ans)
    {
        if (target < 0) {
            // If the target becomes negative, there is no point in exploring further.
            return;
        }
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++)
        {
            ds.push_back(candidates[i]);
            findStuff(candidates, target - candidates[i], ds, i, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findStuff(candidates, target, ds, 0, ans);
        return ans;
    }
};