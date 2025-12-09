class Solution {
public:

    int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(r < 0 || c < 0) return 0;
        if(grid[r][c] == 1) return 0;
        if(r == 0 && c == 0) return 1;
        if(dp[r][c] != -1) return dp[r][c];

        int up = solve(r-1,c,grid,dp);

        int left = solve(r, c-1, grid,dp);

        return dp[r][c] = left + up;  
    }
    
    // tabulation....
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); // row
        int n = obstacleGrid[0].size(); // col

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1) {dp[i][j] = 0; continue;}
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, up = 0;

                    if(j > 0) left = dp[i][j-1];
                    if(i > 0) up = dp[i-1][j]; 

                    dp[i][j] = left + up;
                }
            }
        }

        // for(auto i: dp){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }cout<<endl;
        // }cout<<endl;

        return dp[m-1][n-1];
    }
};