class Solution {
public:

    int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(r < 0 || c < 0) return 1e9;
        if(r == 0 && c == 0) return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];

        int up, left;

        up = solve(r-1, c, grid, dp) + grid[r][c];
        left = solve(r, c-1, grid, dp) + grid[r][c];

        return dp[r][c] = min(up , left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = solve(m-1, n-1, grid, dp);

        return ans;
    }
};