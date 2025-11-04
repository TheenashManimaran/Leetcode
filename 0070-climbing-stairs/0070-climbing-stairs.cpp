class Solution {
public:
    int func(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n < 0 ) return 0;

        if(dp[n] != -1) return dp[n];

        int onestep = func(n-1,dp);
        int twostep = func(n-2,dp);

        return dp[n] = onestep + twostep;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2;i<n+1;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};