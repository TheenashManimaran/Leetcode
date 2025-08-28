class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int flag = 0;

        // upper triangle:
        for(int col = 1;col < n; col++){
            int times = n - col;
            vector<int> temp;
            int row = 0;
            int j = col; // column
            while(times--){
                temp.push_back(grid[row++][j++]);
            }
            sort(temp.begin(), temp.end());
            
            times = n - col;
            row = 0; j = col;
            int ind = 0;
            while(times--){
                grid[row++][j++] = temp[ind++];
            }   
        }

        // upper triangle with diagonal:
        for(int row = 0;row < n; row++){
            int times = n - row;
            vector<int> temp;
            int col = 0;
            int r = row; // column
            while(times--){
                temp.push_back(grid[r++][col++]);
            }
            sort(temp.begin(), temp.end(), greater<int>());
            
            times = n - row;
            r = row; col = 0;
            int ind = 0;
            while(times--){
                grid[r++][col++] = temp[ind++];
            }   
        }

        return grid;

    }
};