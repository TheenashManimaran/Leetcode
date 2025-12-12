class Solution {
public:
// recurison : Memoization.........
    int solve(int r, int c, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp){
        if(r == n-1){
            return triangle[r][c];
        }
        if(dp[r][c] != -1) return dp[r][c];

        int down = 1e8, right = 1e8;

        if(r < n-1) down = triangle[r][c] + solve(r+1, c, triangle, n, dp);
        if(r < n-1 && c < n-1) right = triangle[r][c] + solve(r+1, c+1, triangle, n, dp);

        return dp[r][c] = min(down, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        //int ans = solve(0,0,triangle,n,dp);

        dp[0][0] = triangle[0][0];

        for(int r=1;r<n;r++){
            for(int c=0;c<=r;c++){
                int up = INT_MAX, upleft = INT_MAX;

                if(c == r){
                    upleft = dp[r-1][c-1] + triangle[r][c];
                }
                else if(c == 0){
                    up = dp[r-1][c] + triangle[r][c];
                }
                else{
                    upleft = dp[r-1][c-1] + triangle[r][c];
                    up = dp[r-1][c] + triangle[r][c];
                }

                dp[r][c] = min(upleft, up);
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }
};