class Solution {
public:
// just learnt and executed
// 31/8/2025 sunday 9.15 pm

    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int ind = 0; ind < 9; ind++){
            if(board[row][ind] == c) return false;

            if(board[ind][col] == c) return false;

            //board[for row][for col]
            if(board[3 * (row / 3) + ind/3][3 * (col/3) + ind%3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j] == '.'){
                    
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board) == true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
        
    
    }
};