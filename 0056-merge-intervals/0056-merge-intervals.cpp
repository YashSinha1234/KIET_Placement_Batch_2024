class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        vector<vector<int>>ans;
        sort(i.begin(),i.end());
        vector<int>yash = i[0];
        for(auto it : i){
            if(it[0]<=yash[1]){
                yash[1]= max(it[1],yash[1]);
            }
            else {
                ans.push_back(yash);
                yash = it;
            }
        }
        ans.push_back(yash);
        return ans;
    }
};