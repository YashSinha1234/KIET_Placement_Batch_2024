class Solution {
    void solve(int col, vector<string> &board, int n, vector<int> &leftrow, vector<int> &lowerdiagonal, vector<int> &upperdiagonal, vector<vector<string>> &ans){ 
    
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(leftrow[row] == 0 && lowerdiagonal[row+col] == 0 && upperdiagonal[n-1+col-row] == 0){ 
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiagonal[row+col] = 1;
                upperdiagonal[n-1+col-row] = 1;
                solve(col+1, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerdiagonal[row+col] = 0;
                upperdiagonal[n-1+col-row] = 0;
            }
        }
    }

    public:
    vector<vector<string>> solveNQueens(int n) {
      

        vector<string> board(n, string(n, '.')); 
        vector<vector<string>> ans; 
        
        vector<int> leftrow(n, 0);
        vector<int> lowerdiagonal(2*n-1, 0);
        vector<int> upperdiagonal(2*n-1, 0);
        
        solve(0, board, n, leftrow, lowerdiagonal, upperdiagonal, ans);
        
        return ans;
    }
};