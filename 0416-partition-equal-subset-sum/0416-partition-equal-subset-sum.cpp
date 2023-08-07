class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 !=0 ) return false;
        int n = nums.size();
        sum = sum/2;
        bool possible[n+1][sum+1];
        for(int i=1; i<=sum; i++) possible[0][i] = false;
        for(int i=0; i<=n; i++) possible[i][0] = true;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1] > j) possible[i][j] = possible[i-1][j];
                else possible[i][j] = possible[i-1][j-nums[i-1]] || possible[i-1][j];
            }
        }
        return possible[n][sum];
    }
};