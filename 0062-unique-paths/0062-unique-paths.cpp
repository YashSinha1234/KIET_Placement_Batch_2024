class Solution {
public:
    
vector<vector<int>> dp;
    int solve(int m, int n) {
    if(m == 1 || n == 1) return 1;
    if(dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = solve(m-1, n) + solve(m, n-1);
}
    
int uniquePaths(int m, int n) {
    dp.clear();
    dp.assign(m+1, vector<int>(n+1, -1));
    return solve(m, n);
    }
};