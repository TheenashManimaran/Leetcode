class Solution {
public:
    int rec(int row, int col){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;

        int up = rec(row - 1, col);
        int left = rec(row, col - 1);

        return up + left;
    }

    int memoize(int row, int col, vector<vector<int>> dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;

        if(dp[row][col] == -1) return dp[row][row];
        int up = rec(row - 1, col);
        int left = rec(row, col - 1);

        return dp[row][col] = up + left;
    }

    int tabulate(int m, int n, vector<vector<int>> &dp){
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, up = 0;

                    if(j>0) left = dp[i][j-1];
                    if(i > 0) up = dp[i-1][j];

                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m-1][n-1];
    }

    int spaceOpt(int m, int n){
        vector<int> prev(n,1);

        for(int i = 1;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){

                if(j>0) temp[j] = temp[j-1] + prev[j];
                else temp[j] = prev[j];
            }
            prev = temp;
        }
        return prev[n-1];
    }

    int uniquePaths(int m, int n) {
        // recursive approach:
        // from index n-1 to 0:

        //return rec(m-1,n-1);

        vector<vector<int>> dp(m, vector<int>(n));
        //return memoize(m-1,n-1,dp);

        // return tabulate(m,n,dp);

        return spaceOpt(m,n);
    }
};