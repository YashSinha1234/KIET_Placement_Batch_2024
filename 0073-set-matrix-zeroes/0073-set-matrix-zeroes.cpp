class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<int>> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        vector<int> yash;
        for (int j = 0; j < m; j++) {
            yash.push_back(1);
        }
        ans.push_back(yash);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < m; k++) {
                    ans[i][k] = 0;
                }
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < n; k++) {
                    ans[k][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    }
};