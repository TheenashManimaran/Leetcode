class Solution {
public:
    int recur(int i, int j, vector<vector<int>> &mat){
        /*
        i - row; j - col
        */
        if(i == 0 && j == 0 && mat[i][j] == 0 ){
            return 1;
        }
        if(i < 0 || j < 0) return 0;
        if(mat[i][j] == 1) return 0;

        int left = recur(i,j - 1,mat);
        int up = recur(i-1, j,mat);

        return left + up;
    }

    int memoize(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
        /*
        i - row; j - col
        */
        if(i == 0 && j == 0 && mat[i][j] == 0 ){
            return 1;
        }
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(mat[i][j] == 1) return dp[i][j] = 0;
        

        int left = recur(i,j - 1,mat);
        int up = recur(i-1, j,mat);

        return dp[i][j] = left + up;
    }

    int tabulate(int m, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, up = 0;
                    if(j > 0) left = dp[i][j-1];
                    if(i > 0) up = dp[i-1][j];
                    dp[i][j] = left + up;
                }
            }

        }

        return dp[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        //return recur(m-1, n-1, obstacleGrid);

        //return memoize(m-1, n-1, obstacleGrid, dp);

        return tabulate(m, n, obstacleGrid, dp);
    }
};