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
//  SpaceOptimization....
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n);

        for(int i=0;i<m;i++){
            vector<int> cur(n);
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0) cur[j] = grid[i][j];

                else{
                    int up = 1e9, left = 1e9;

                    if(i > 0) up = grid[i][j] + prev[j];
                    if(j > 0) left = grid[i][j] + cur[j-1];

                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n-1];

    }
};