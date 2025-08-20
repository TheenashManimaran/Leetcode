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



    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n,-1);
        
        int startWith0 = funcWith0(0, cost, n,dp);

        for(auto &i : dp) i = -1;

        int startWith1 = funcWith1(1,cost,n,dp);

        return min(startWith0, startWith1);
    }
};