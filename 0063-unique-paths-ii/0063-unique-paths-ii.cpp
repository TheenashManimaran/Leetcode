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
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); // row
        int n = obstacleGrid[0].size(); // col

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = solve(m-1, n-1, obstacleGrid, dp);

        return ans;
    }
};