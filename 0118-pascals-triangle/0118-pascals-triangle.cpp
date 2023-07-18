class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yash(numRows);
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i+1, 1);
            int mid = i >> 1;
            for (int j = 1; j <= mid; j++) {
                int val = yash[i-1][j-1] + yash[i-1][j];
                row[j] = val;
                row[row.size()-j-1] = val;
            }
            yash[i] = row;
        }
        return yash;
    }
};