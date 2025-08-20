class Solution {
public:
    int funcWith0(int ind, vector<int> &cost, int n, vector<int> &dp){
        if(ind == n-1){
            return cost[ind];
        }
        if(ind > n-1) return 0;
        if(dp[ind] != -1) return dp[ind];

        int step1 = funcWith0(ind+1,cost,n,dp) + cost[ind];
        int step2 = INT_MAX;
        step2 = funcWith0(ind+2, cost,n,dp) + cost[ind];

        return dp[ind] = min(step1, step2);
    }

    int funcWith1(int ind, vector<int> &cost, int n, vector<int> &dp){
        if(ind == n-1){
            return cost[ind];
        }
        if(ind > n-1) return 0;
        if(dp[ind] != -1) return dp[ind];

        int step1 = funcWith1(ind+1,cost,n,dp) + cost[ind];
        int step2 = INT_MAX;
        step2 = funcWith1(ind+2, cost,n,dp) + cost[ind];

        return dp[ind] = min(step1, step2);
    }

    int tabulate(int base, int n, vector<int> &cost, vector<int>&dp){
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<n;i++){
            int step1 = dp[i-1] + cost[i];
            int step2 = INT_MAX;
            if(i - 2 >= 0){
                step2 = dp[i-2] + cost[i];
            }
            else step2 = cost[i];
            dp[i] = min(step1 , step2);
        }

        return min(dp[n-1],dp[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n,-1);
        
        // int startWith0 = funcWith0(0, cost, n,dp);

        // for(auto &i : dp) i = -1;

        // int startWith1 = funcWith1(1,cost,n,dp);

        int startWith0 = tabulate(0,n, cost,dp);

        for(auto &i: dp) i = -1;
        int startWith1 = tabulate(1,n,cost,dp);
        

        return min(startWith0, startWith1);
    }
};