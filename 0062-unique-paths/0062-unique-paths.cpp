class Solution {
public:
    
    int solve(int r, int c, vector<vector<int>> &dp){
        if(r == 0 && c == 0) return 1;
        if(r < 0 || c < 0) return 0;
        if(dp[r][c] != -1) return dp[r][c];

        int up = solve(r-1,c,dp);

        int left = solve(r, c-1, dp);

        return dp[r][c] = up + left;

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
//.....................................Tabulation
        dp[0][0] = 1;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){

                if(r == 0 && c == 0) continue;

                int left = 0, up = 0;

                if(r > 0) up = dp[r-1][c];

                if(c > 0) left = dp[r][c-1];

                dp[r][c] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};

/*
steps to convert memoization to tabultaion

1. Base case
2. express the states as for loop eg. r - for i , c - inner for j
3. copy the recurrence

*/