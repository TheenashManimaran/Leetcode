class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();

        int xx = x, yy = y;
        vector<vector<int>> mat;

        for(int i=0;i<m;i++){
            int flag = 0;
            vector<int> temp;
            for(int j = 0;j<n;j++){
                if(flag == 0 && i == xx && j == yy ){
                    temp.push_back(grid[i][j]);
                    flag = 1;
                    yy++;
                }  
                else if(flag == 1 && i == xx && j == yy){
                    temp.push_back(grid[i][j]);
                    yy++;
                }
                if(yy > k + y -1){
                    yy = y;
                    break;
                }
            }
            if(!temp.empty()){
                mat.push_back(temp);
                xx++;
            }
            if(xx > k + x -1){
                break;
            }
        }

        
        int mm = mat.size();
        int nn = mat[0].size();

        for(int i=0;i<mm/2;i++){
            for(int j=0;j<nn;j++){
                swap(mat[i][j] , mat[mm - i - 1][j]);
            }
        }

        xx = x, yy = y;
        int matr = 0, matc = 0;
        for(int i=0;i<m;i++){
            int flag = 0;
            for(int j=0;j<n;j++){
                
                if(flag == 0 && i == xx && j == yy){
                    grid[i][j] = mat[matr][matc++];
                    yy++;
                    flag = 1;
                }
                else if(flag && i == xx && j == yy){
                    grid[i][j] = mat[matr][matc++];
                    yy++;
                }
                if(yy > k + y -1){
                    xx++;
                    yy = y;
                    matc = 0;
                    matr++;
                    break;
                }
            }
            if(xx > k + x - 1) break;
        }

        return grid;
    }
};