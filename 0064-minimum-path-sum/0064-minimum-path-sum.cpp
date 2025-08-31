class Solution {
public:
    // recursive solution

    int func(int i,int j, int n, int m, vector<vector<int>> &grid){
        if(j > m - 1 || i > n-1) return 1e4;
        if(i == n-1 && j == m-1) return grid[i][j];

        int right = grid[i][j] + func(i, j+1, n, m, grid);
        int down = grid[i][j] + func(i+1, j, n, m, grid);

        return min(right, down);
    }

    int memoize(int i,int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(j > m - 1 || i > n-1) return 1e9;
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int right = grid[i][j] + memoize(i, j+1, n, m, grid, dp);
        int down = grid[i][j] + memoize(i+1, j, n, m, grid, dp);

        return dp[i][j] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = memoize(0,0,n,m,grid,dp);
        return ans;
    }
};