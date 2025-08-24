class NumMatrix {
public:

    vector<vector<int>> ps;

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        ps.assign(n + 1, vector<int>(m + 1, 0)); // prefix matrix
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ps[i+1][j+1] = matrix[i][j] + ps[i+1][j] + ps[i][j+1] - ps[i][j];
                // ps[r][c] = mat[r][c] + ps[r][c-1] + ps[r-1][c] - ps[r-1][c-1]
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = ps[row2 + 1][col2 + 1] - ps[row2+1][col1] - ps[row1][col2+1] + ps[row1][col1];
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */