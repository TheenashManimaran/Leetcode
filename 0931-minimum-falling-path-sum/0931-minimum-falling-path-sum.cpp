class Solution {
public:

    int solve(int r, int c, vector<vector<int>> matrix, int n, vector<vector<int>> dp){
        if(c < 0 || c > n-1) return 1e9;
        if(r == 0) return matrix[r][c];

        int up, upleft, upright;

        up = matrix[r][c] + solve(r-1, c, matrix, n, dp);

        upleft = matrix[r][c] + solve(r-1, c-1, matrix, n, dp);

        upright = matrix[r][c] + solve(r-1, c+1, matrix, n, dp);

        return dp[r][c] = min(up, min(upleft, upright));
    }

    int tabulate(int n, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        for(int i = 0;i<n;i++) {
            dp[0][i] = matrix[0][i];
        }

        for(int r = 1; r < n; r++){
            for(int c = 0; c < n; c++){
                int up = 1e9, upleft = 1e9, upright = 1e9;

                if(c > 0) upleft = matrix[r][c] + dp[r-1][c-1];
                if(c < n-1) upright = matrix[r][c] + dp[r-1][c+1];
                up = matrix[r][c] + dp[r-1][c];

                dp[r][c] = min(up, min(upleft, upright));
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // int mini = INT_MAX;
        // for(int i=0;i<n;i++){
        //     vector<vector<int>> dp(n, vector<int>(n, -1));
        //     mini = min(solve(n-1, , matrix, n, dp), mini);
        // }

        // return mini;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = tabulate(n, matrix, dp);

        return ans;
    }
};