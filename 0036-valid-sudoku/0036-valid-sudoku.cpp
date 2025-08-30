class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0;i<n;i++){
            int x, y;
            for(int j=0;j<n;j++){
                // up 
                y = i;
                while(y > 0){
                    y--;
                    if(board[i][j] != '.' && board[i][j] == board[y][j]) {return false;}
                }

                // down
                y = i;
                while(y < n-1){
                    y++;
                    if(board[i][j] != '.' && board[i][j] == board[y][j]) {return false;}
                }

                // left
                x = j;
                while(x > 0){
                    x--;
                    if(board[i][j] != '.' && board[i][j] == board[i][x]) {return false;}
                }

                // right
                x = j;
                while(x < n-1){
                    x++;
                    if(board[i][j] != '.' && board[i][j] == board[i][x]) {return false;}

                }
            }
        }

        for(int sqi=0; sqi<n; sqi+=3){
            for(int sqj = 0; sqj < n; sqj += 3){
                map<char,int> mapp;

                // for(int i = sqi;i<(3 + sqi);i++){
                //     for(int j = sqj; j < (3 + sqj) ; j++){
                //         cout<<board[i][j]<<" ";
                //     }cout<<endl;
                // }
                // cout<<endl<<endl;

                for(int i = sqi; i<3 + sqi; i++){
                    for(int j = 0 + sqj; j < 3 + sqj ; j++){
                        if(board[i][j] == '.') continue;
                        mapp[board[i][j]]++;
                        if(mapp[board[i][j]] > 1) {return false;}
                    }
                }

            }
        }

        return true;
    }

    
};