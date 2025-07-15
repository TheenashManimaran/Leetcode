class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n){
        // upper diagnol
        int dupRow = row;
        int dupCol = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') {
                return false;
            }
            col--; row--;
        }

        // left
        row = dupRow;
        col = dupCol;
        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        //lower left
        row = dupRow;
        col = dupCol;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++; col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n,int &count){
        if(col == n){
            ans.push_back(board);
            count++;
            return;
        }

        for(int r=0;r<n;r++){
            if(isSafe(r,col,board,n)){
                board[r][col] = 'Q';
                solve(col+1, board, ans, n,count);
                board[r][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');

        for(int i=0;i<n;i++){
            board[i] = s;
        }
        int count = 0;
        solve(0,board,ans,n,count);

        return ans;
    }
};