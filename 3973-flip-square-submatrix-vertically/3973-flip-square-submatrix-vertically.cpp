class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> &grid, int x, int y, int k){
        int m = grid.size(), n = grid[0].size();

        int l = x, r = x + k - 1;

        while(l < r){
            for(int i=y;i<=y+k-1;i++){
                swap(grid[l][i], grid[r][i]);
            }
            l++; r--;
        }
        
        return grid;
    }

    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {


        return solve(grid,x,y,k);

        int m = grid.size(), n = grid[0].size();

        int xx = x, yy = y;
        vector<vector<int>> mat;

// ...................finding the Square submatrix and storing as new matrix..............
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

// ...............................swapping the submatrix................
        for(int i=0;i<mm/2;i++){
            for(int j=0;j<nn;j++){
                swap(mat[i][j] , mat[mm - i - 1][j]);
            }
        }

// .............................storing the swapped submatrix to the original matrix itself
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

        /*
        t.c :
        0(m * n) - for traversing the matrix to find the submatrix
        O(mm * nn) - for swapping in th submatrix (mm == nn == k)
        O(m * n) - for modifying the swapped submatrx in original matrix

        overall :: 2 * O(m * n) + O(k * k)

        space complexity :
        extra space for storing submatrix

        s.c = O(k*k)
        */

        return grid;


    }
};