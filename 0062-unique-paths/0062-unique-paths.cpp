class Solution {
public:
    
    int solve(int r, int c, int m, int n, vector<vector<int>> &dp){
        if(r == m-1 && c == n-1){
            return 1;
        }
        if(dp[r][c] != -1) return dp[r][c];

        
        int down = 0, right = 0;
        if(r < m-1) down = solve(r+1,c,m,n, dp);

        if(c < n-1) right = solve(r, c+1,m,n, dp);

        return dp[r][c] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0,0,m,n, dp);
    }
};